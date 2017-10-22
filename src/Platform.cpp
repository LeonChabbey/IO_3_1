#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include <string>
#include <utilities.h>
#include "Platform.h"

Platform::Platform(b2World* world, float width, float height, float posX, float posY, sf::Color color, b2BodyType type) : RectangleEntity(world, width, height, posX, posY, color, type)
{
	// Main fixture userData for collision detection
	userData->instance = this;
	userData->className = "Platform";
	bodyFixture->SetUserData(userData);
}

Platform::~Platform()
{
}
