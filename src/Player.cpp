#include <iostream>
#include "Player.h"
#include <string>

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

Player::Player(float width, float height) : EntityManager(width, height) {
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(sf::Color::Yellow);
}

sf::RectangleShape Player::getShape() {
	return shape;
}

void Player::update() {
	std::cout << "Player //// body X: " << body->GetPosition().x << " /// body Y: " << body->GetPosition().y << "\n" << std::flush;
	std::cout << "Player //// shape X: " << shape.getPosition().x << " /// shape Y: " << shape.getPosition().x << "\n" << std::flush;
	shape.setPosition(body->GetPosition().x, body->GetPosition().y);
}

void Player::draw(sf::RenderWindow & window) {
	window.draw(shape);
}

Player::~Player()
{
}
