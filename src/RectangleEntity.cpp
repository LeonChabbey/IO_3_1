#include "RectangleEntity.h"
#include <iostream>
#include <utilities.h>

RectangleEntity::RectangleEntity(b2World* world, float width, float height, float posX, float posY, sf::Color color, b2BodyType type) {
	shape.setOrigin(sf::Vector2f(width / 2, height / 2));
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(color);

	bodyDef.position.Set(pixel2meter(posX+width/2), pixel2meter(posY + height / 2));
	bodyDef.type = type;

	bodyShape.SetAsBox(pixel2meter(width)/2, pixel2meter(height)/2);

	bodyFixtureDef.shape = &bodyShape;
	bodyFixtureDef.density = 1;

	body = world->CreateBody(&bodyDef);
	bodyFixture = body->CreateFixture(&bodyFixtureDef);

	body->SetUserData(this);
}

b2PolygonShape& RectangleEntity::getBodyShape() {
	return bodyShape;
}

b2BodyDef& RectangleEntity::getBodyDef() {
	return bodyDef;
}

b2FixtureDef& RectangleEntity::getBodyFixtureDef() {
	return bodyFixtureDef;
}

b2Body* RectangleEntity::getBody() {
	return body;
}

b2Fixture* RectangleEntity::getBodyFixture() {
	return bodyFixture;
}

sf::RectangleShape RectangleEntity::getShape() {
	return shape;
}

void RectangleEntity::update() {
	//std::cout << "Plat //// body X: " << body->GetPosition().x << " /// body Y: " << body->GetPosition().y << "\n" << std::flush;
	//std::cout << "Plat //// shape X: " << shape.getPosition().x << " /// shape Y: " << shape.getPosition().y << "\n" << std::flush;
	shape.setPosition(meter2pixel(body->GetPosition().x), meter2pixel(body->GetPosition().y));
}

void RectangleEntity::draw(sf::RenderWindow & window) {
	window.draw(shape);
}

RectangleEntity::~RectangleEntity()
{
}
