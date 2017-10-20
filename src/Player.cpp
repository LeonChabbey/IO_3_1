#include <iostream>
#include "Player.h"
#include <string>

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

Player::Player(float width, float height) {
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(sf::Color::Red);

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0, 0);

	bodyShape.SetAsBox(width, height);
	bodyFixtureDef.shape = &bodyShape;
}

void Player::setB2Body(b2Body* newBody) {
	body = newBody;
}

b2BodyDef Player::getBodyDef() {
	return bodyDef;
}

void Player::update() {



	shape.setPosition(body->GetPosition().x, body->GetPosition().y);
}

void Player::draw(sf::RenderWindow & window) {
	window.draw(shape);
}

Player::~Player()
{
}
