#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "RectangleEntity.h"

enum class PlayerState {
	MOVING,
	JUMPING
};

class Player : public RectangleEntity {
private:
	PlayerState state;
public:
	Player(b2World*, float, float, float, float, sf::Color, b2BodyType);

	void update() override;

	~Player();
};


#endif // !PLAYER_H
