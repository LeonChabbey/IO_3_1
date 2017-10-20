#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

class EntityManager {
protected:
	b2PolygonShape bodyShape;
	b2BodyDef bodyDef;
	b2FixtureDef bodyFixtureDef;
	b2Body* body;
	b2Fixture* bodyFixture;
public:
	EntityManager(float, float);

	void addBodyToWorldAndCreateFixture(b2World*);

	b2PolygonShape& getBodyShape();
	b2BodyDef& getBodyDef();
	b2FixtureDef& getBodyFixtureDef();
	b2Body* getBody();
	b2Fixture* getBodyFixture();

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow&) = 0;

	~EntityManager();
};

#endif // !ENTITY_MANAGER_H
