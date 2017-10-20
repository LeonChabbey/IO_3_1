#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <Box2D/Box2D.h>

#include "json.hpp"
#include "Player.h"
#include "Platform.h"

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

	Player player(playerConfig["width"], playerConfig["height"]);
	player.addBodyToWorldAndCreateFixture(myWorld);

	Platform floor(windowConfig["width"], floorConfig["height"]);
	floor.getBodyDef().type = b2_staticBody;
	floor.getBodyDef().position.Set(0, (float)windowConfig["height"] - (float)floorConfig["height"]);
	floor.addBodyToWorldAndCreateFixture(myWorld);

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			std::cout << "Right\n" << std::flush;
			player.getBody()->ApplyForce(b2Vec2(50, 10), player.getBody()->GetWorldCenter(), 0);
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