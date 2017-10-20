#include <iostream>
#include "Player.h"
#include <string>

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

Player::Player(float width, float height) {
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(sf::Color::Yellow);

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0, 0);

	bodyShape.SetAsBox(width, height);
	bodyFixtureDef.shape = &bodyShape;
	bodyFixtureDef.density = 1;
}

void Player::setB2Body(b2Body* newBody) {
	body = newBody;
}

void Player::setB2Fixture(b2Fixture * newFixture)
{
	bodyFixture = newFixture;
}

b2FixtureDef Player::getFixtureDef()
{
	return bodyFixtureDef;
}

b2BodyDef Player::getBodyDef() {
	return bodyDef;
}

b2Body * Player::getBody() {
	return body;
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
