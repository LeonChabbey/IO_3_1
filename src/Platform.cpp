#include <iostream>
#include "Platform.h"
#include <string>

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

Platform::Platform(float width, float height) : EntityManager(width, height) {
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(sf::Color::Blue);
}

sf::RectangleShape Platform::getShape() {
	return shape;
}

void Platform::update() {
	std::cout << "Plat //// body X: " << body->GetPosition().x << " /// body Y: " << body->GetPosition().y << "\n" << std::flush;
	std::cout << "Plat //// shape X: " << shape.getPosition().x << " /// shape Y: " << shape.getPosition().x << "\n" << std::flush;
	shape.setPosition(body->GetPosition().x, body->GetPosition().y);
}

void Platform::draw(sf::RenderWindow & window) {
	window.draw(shape);
}

Platform::~Platform()
{
}