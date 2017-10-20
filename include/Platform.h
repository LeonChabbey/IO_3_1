#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "EntityManager.h"

class Platform : public EntityManager {
private:
	sf::RectangleShape shape;
public:
	Platform(float, float);

	sf::RectangleShape getShape();

	virtual void update();
	virtual void draw(sf::RenderWindow& window);

	~Platform();
};


#endif // !PLATFORM_H
