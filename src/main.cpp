#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <Box2D/Box2D.h>

#include "json.hpp"
#include "Player.h"

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
	json playerConfig = config["player"];
	json platformConfig = config["platforms"];

	sf::RenderWindow window(sf::VideoMode(windowConfig["width"], windowConfig["height"]), "SFML works!");
	window.setFramerateLimit(windowConfig["frameRateLimit"]);

	Player player(playerConfig["width"], playerConfig["height"]);
	player.setB2Body(myWorld->CreateBody(&player.getBodyDef()));

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color(2, 56, 37));
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
	myBodyDef.position.Set(0, 0); //set the starting position
	b2Body* dynamicBody = myWorld->CreateBody(&myBodyDef);

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
		

		shape.setPosition(dynamicBody->GetPosition().x, dynamicBody->GetPosition().y);

		player.update();
		window.clear();
		player.draw(window);
		window.draw(shape);
		
		window.display();
	}
	delete myWorld;

	system("pause");
	return 0;
}