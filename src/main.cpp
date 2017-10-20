#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <Box2D/Box2D.h>

#include "json.hpp"
#include "Player.h"

#define CONFIG_FILE "../data/config.json"
#define RATIO_PIXEL_METER 64

using json = nlohmann::json;

float pixel2meter(float a)
{
	return a / RATIO_PIXEL_METER;
}

float meter2pixel(float a)
{
	return a * RATIO_PIXEL_METER;
}

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
	player.setB2Body(myWorld->CreateBody(&player.getBodyDef()));
	player.getBody()->CreateFixture(&player.getFixtureDef());

	b2PolygonShape FloorShape;
	FloorShape.SetAsBox(windowConfig["width"], 0.f);

	b2FixtureDef FloorFixtureDef;
	FloorFixtureDef.shape = &FloorShape;
	FloorFixtureDef.density = 10;

	b2BodyDef theFloor;
	theFloor.type = b2_staticBody;
	theFloor.position.Set(0, (float)windowConfig["height"] - 100.f);
	b2Body* staticBody = myWorld->CreateBody(&theFloor);
	staticBody->CreateFixture(&FloorFixtureDef);

	sf::RectangleShape Floor(sf::Vector2f(windowConfig["width"], floorConfig["height"]));
	Floor.setFillColor(sf::Color(100, 56, 37));

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
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code) {
				case sf::Keyboard::Up:
					std::cout << "Up\n" << std::flush;
					break;
				}
			}
		}
		
		Floor.setPosition(staticBody->GetPosition().x, staticBody->GetPosition().y);

		player.update();
		window.clear();
		player.draw(window);
		window.draw(Floor);
		window.display();
	}
	delete myWorld;

	system("pause");
	return 0;
}