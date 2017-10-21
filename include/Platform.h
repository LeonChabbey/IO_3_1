#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "RectangleEntity.h"

class Platform : public RectangleEntity {
public:
	Platform(b2World*, float, float, float, float, sf::Color, b2BodyType);

	~Platform();
};


#endif // !PLATFORM_H
