#include <iostream>
#include "Player.h"
#include <string>
#include <utilities.h>

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

#define SENSOR_HEIGHT 10.f
#define JUMP_FORCE 3.f
#define MOVING_SPEED 3.f

Player::Player(b2World* world, float width, float height, float posX, float posY, sf::Color color, b2BodyType type) : RectangleEntity(world, width, height, posX, posY, color, type)
{
	// Main fixture (the player shape itself) userData for collision detection
	userData->instance = this;
	userData->className = "Player";
	bodyFixture->SetUserData(userData);

	// Foot fixture userData to detect if the player is on the ground
	bodyShape.SetAsBox(pixel2meter(width/2) / 2, pixel2meter(SENSOR_HEIGHT) / 2, b2Vec2(0, pixel2meter(height)/2), 0);
	bodyFixtureDef.isSensor = true;
	footSensorFixture = body->CreateFixture(&bodyFixtureDef);

	UserDataStruct* userDataSensor = new UserDataStruct;
	userDataSensor->instance = this;
	userDataSensor->className = "PlayerFoot";

	footSensorFixture->SetUserData(userDataSensor);

	state = PlayerState::MOVING;
}

void Player::playerOnGround() {
	//std::cout << "switch to ground\n" << std::flush;
	state = PlayerState::MOVING;
}

void Player::playerInAir() {
	//std::cout << "switch to air\n" << std::flush;
	state = PlayerState::JUMPING;
}

void Player::update() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		body->ApplyForce(b2Vec2(-MOVING_SPEED, 0), body->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		body->ApplyForce(b2Vec2(MOVING_SPEED, 0), body->GetWorldCenter(), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && state != PlayerState::JUMPING) {
		body->ApplyLinearImpulse(b2Vec2(0, body->GetMass() * -JUMP_FORCE), body->GetWorldCenter(), true);
	}  

	//std::cout << "Plat //// body X: " << body->GetPosition().x << " /// body Y: " << body->GetPosition().y << "\n" << std::flush;
	//std::cout << "Plat //// shape X: " << shape.getPosition().x << " /// shape Y: " << shape.getPosition().y << "\n" << std::flush;
	shape.setPosition(meter2pixel(body->GetPosition().x), meter2pixel(body->GetPosition().y));
}

Player::~Player()
{
}
