#include <iostream>
#include "Player.h"
#include <string>
#include <utilities.h>

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

Player::Player(b2World* world, float width, float height, float posX, float posY, sf::Color color, b2BodyType type) : RectangleEntity(world, width, height, posX, posY, color, type)
{
	userData->className = "Player";
	body->SetUserData(userData);

	state = PlayerState::MOVING;
}

void Player::playerOnGround() {
	std::cout << "switch to ground\n" << std::flush;
	state = PlayerState::MOVING;
}

void Player::playerInAir() {
	std::cout << "switch to air\n" << std::flush;
	state = PlayerState::JUMPING;
}

void Player::update() {

	std::cout << "Player current state: " << (int)state << "\n" << std::flush;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		body->ApplyForce(b2Vec2(-3, 0), body->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		body->ApplyForce(b2Vec2(3, 0), body->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && state != PlayerState::JUMPING) {
		body->ApplyForce(b2Vec2(0, -50), body->GetWorldCenter(), true);
	}


	//std::cout << "Plat //// body X: " << body->GetPosition().x << " /// body Y: " << body->GetPosition().y << "\n" << std::flush;
	//std::cout << "Plat //// shape X: " << shape.getPosition().x << " /// shape Y: " << shape.getPosition().y << "\n" << std::flush;
	shape.setPosition(meter2pixel(body->GetPosition().x), meter2pixel(body->GetPosition().y));
}

Player::~Player()
{
}
