#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <Box2D/Box2D.h>

#include "json.hpp"
#include "Player.h"
#include "RectangleEntity.h"
#include "utilities.h"

#define CONFIG_FILE "../data/config.json"

using json = nlohmann::json;

int main()
{
	b2Vec2 gravity(0, 9.8); //normal earth gravity, 9.8 m/s/s straight down!
	b2World* myWorld = new b2World(gravity);

	// Config json
	std::ifstream i(std::string(CONFIG_FILE));
	json config;
	i >> config;

	json windowConfig = config["window"];
	json floorConfig = config["floor"];
	json playerConfig = config["player"];
	json platformConfig = config["platforms"];

	sf::RenderWindow window(sf::VideoMode(windowConfig["width"], windowConfig["height"]), "SFML works!");
	window.setFramerateLimit(windowConfig["frameRateLimit"]);

	const float PLAYER_START_X = 50,
		PLAYER_START_Y = (float)windowConfig["height"] - (float)floorConfig["height"] - 100.f;

	const sf::Color PLAYER_COLOR = convertJsonToSfColor(playerConfig["color"]);

	Player player(myWorld, playerConfig["width"], playerConfig["height"], PLAYER_START_X, PLAYER_START_Y, PLAYER_COLOR, b2_dynamicBody);

	const float FLOOR_POS_X = 0,
		FLOOR_POS_Y = (float)windowConfig["height"] - (float)floorConfig["height"];

	const sf::Color FLOOR_COLOR = convertJsonToSfColor(floorConfig["color"]);

	RectangleEntity floor(myWorld, (float)windowConfig["width"], floorConfig["height"], FLOOR_POS_X, FLOOR_POS_Y, FLOOR_COLOR, b2_staticBody);

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

		player.update();
		floor.update();
		window.clear();
		floor.draw(window);
		player.draw(window);
		window.display();
	}
	delete myWorld;

	system("pause");
	return 0;
}