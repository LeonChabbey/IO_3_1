#include <iostream>
#include "Player.h"
#include <string>
#include <utilities.h>

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

Player::Player(b2World* world, float width, float height, float posX, float posY, sf::Color color, b2BodyType type) : RectangleEntity(world, width, height, posX, posY, color, type)
{
	state = PlayerState::IDLE;
}

void Player::update() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		std::cout << "Right\n" << std::flush;
		body->ApplyForce(b2Vec2(3, 1), body->GetWorldCenter(), true);
	}

	std::cout << "Plat //// body X: " << body->GetPosition().x << " /// body Y: " << body->GetPosition().y << "\n" << std::flush;
	std::cout << "Plat //// shape X: " << shape.getPosition().x << " /// shape Y: " << shape.getPosition().y << "\n" << std::flush;
	shape.setPosition(meter2pixel(body->GetPosition().x), meter2pixel(body->GetPosition().y));
}

Player::~Player()
{
}
