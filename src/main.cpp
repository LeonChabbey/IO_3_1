#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <Box2D/Box2D.h>

#include "json.hpp"
#include "Player.h"
#include "Platform.h"
#include "PlatformsManager.h"
#include "ContactListener.h"
#include "utilities.h"

#define CONFIG_FILE "../data/config.json"

using json = nlohmann::json;

int main()
{
	srand(time(NULL));

	b2Vec2 gravity(0, 9.8); //normal earth gravity, 9.8 m/s/s straight down!
	b2World* myWorld = new b2World(gravity);
	// Contact Listener
	ContactListener myContactListener;
	myWorld->SetContactListener(&myContactListener);

	// Config json
	std::ifstream i(std::string(CONFIG_FILE));
	json config;
	i >> config;

	json windowConfig = config["window"];
	json floorConfig = config["floor"];
	json playerConfig = config["player"];
	json platformsConfig = config["platforms"];

	sf::RenderWindow window(sf::VideoMode(windowConfig["width"], windowConfig["height"]), "SFML works!");
	window.setFramerateLimit(windowConfig["frameRateLimit"]);

	// Platforms
	PlatformsManager platformsManager(&window, myWorld, windowConfig, platformsConfig);

	// Player
	const float PLAYER_START_X = 50,
		PLAYER_START_Y = (float)windowConfig["height"] - (float)floorConfig["height"] - 100.f;

	const sf::Color PLAYER_COLOR = convertJsonToSfColor(playerConfig["color"]);

	Player player(myWorld, playerConfig["width"], playerConfig["height"], PLAYER_START_X, PLAYER_START_Y, PLAYER_COLOR, b2_dynamicBody);

	// Floor
	const float FLOOR_POS_X = 0,
		FLOOR_POS_Y = (float)windowConfig["height"] - (float)floorConfig["height"];

	const sf::Color FLOOR_COLOR = convertJsonToSfColor(floorConfig["color"]);

	Platform floor(myWorld, (float)windowConfig["width"], floorConfig["height"], FLOOR_POS_X, FLOOR_POS_Y, FLOOR_COLOR, b2_staticBody);

	float32 timeStep = 1 / 60.0;      //the length of time passed to simulate (seconds)
	int32 velocityIterations = 8;   //how strongly to correct velocity
	int32 positionIterations = 3;   //how strongly to correct position

	float speed = 5.0f;
	while (window.isOpen())
	{
		myWorld->Step(timeStep, velocityIterations, positionIterations);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		platformsManager.update();
		player.update();
		floor.update();
		window.clear();
		player.draw(window);
		floor.draw(window);
		platformsManager.draw();
		window.display();
	}
	delete myWorld;

	system("pause");
	return 0;
}