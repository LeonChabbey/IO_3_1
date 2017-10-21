#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <utilities.h>

class RectangleEntity {
protected:
	sf::RectangleShape shape;
	b2PolygonShape bodyShape;
	b2BodyDef bodyDef;
	b2FixtureDef bodyFixtureDef;
	b2Body* body;
	b2Fixture* bodyFixture;
	b2World* world;
	UserDataStruct* userData = new UserDataStruct;
public:
	RectangleEntity(b2World*, float, float, float, float, sf::Color, b2BodyType);

	b2PolygonShape& getBodyShape();
	b2BodyDef& getBodyDef();
	b2FixtureDef& getBodyFixtureDef();
	b2Body* getBody();
	b2Fixture* getBodyFixture();
	sf::RectangleShape getShape();

	virtual void update();
	virtual void draw(sf::RenderWindow&);

	~RectangleEntity();
};

#endif // !ENTITY_MANAGER_H
