#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

class Player {
private:
	sf::RectangleShape shape;
	b2PolygonShape bodyShape;
	b2BodyDef bodyDef;
	b2FixtureDef bodyFixtureDef;
	b2Body* body;
	b2Filter* bodyFixture;
public:
	Player(float, float);

	void setB2Body(b2Body*);

	b2BodyDef getBodyDef();

	void update();
	void draw(sf::RenderWindow& window);

	~Player();
};


#endif // !PLAYER_H
