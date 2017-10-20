#include <SFML/Graphics.hpp>
#include <iostream>

#include <Box2D/Box2D.h>

#define RATIO_PIXEL_METER 64

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


	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60.f);

	sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
	shape.setFillColor(sf::Color(2, 56, 37));
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
	myBodyDef.position.Set(100, 100); //set the starting position
	b2Body* dynamicBody = myWorld->CreateBody(&myBodyDef);


	b2PolygonShape boxShape;
	boxShape.SetAsBox(100.f, 100.f);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	dynamicBody->CreateFixture(&boxFixtureDef);

	b2PolygonShape FloorShape;
	FloorShape.SetAsBox(800.f, 0.f);

	b2FixtureDef FloorFixtureDef;
	FloorFixtureDef.shape = &FloorShape;
	FloorFixtureDef.density = 10;
	

	b2BodyDef theFloor;
	theFloor.type = b2_staticBody;
	theFloor.position.Set(0, 550);
	b2Body* staticBody = myWorld->CreateBody(&theFloor);
	staticBody->CreateFixture(&FloorFixtureDef);


	sf::RectangleShape Floor(sf::Vector2f(800.f, 40.f));
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
				if (event.key.code == sf::Keyboard::Space)
				{
					std::cout << "User pressed SPACE\n";
				}
			}
		}
		

		shape.setPosition(dynamicBody->GetPosition().x, dynamicBody->GetPosition().y);
		Floor.setPosition(staticBody->GetPosition().x, staticBody->GetPosition().y);


		window.clear();
		window.draw(Floor);
		window.draw(shape);
		
		window.display();
	}
	delete myWorld;

	system("pause");
	return 0;
}