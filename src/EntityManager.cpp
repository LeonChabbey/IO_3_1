#include "..\include\EntityManager.h"
#include <iostream>
#include <utilities.h>

EntityManager::EntityManager(float width, float height) {
	bodyDef.position.Set(0.f, 0.f);
	bodyDef.type = b2_dynamicBody;

	bodyShape.SetAsBox(pixel2meter(width/2), pixel2meter(height/2));

	bodyFixtureDef.shape = &bodyShape;
	bodyFixtureDef.density = 1;
}

void EntityManager::addBodyToWorldAndCreateFixture(b2World* world) {
	body = world->CreateBody(&bodyDef);
	bodyFixture = body->CreateFixture(&bodyFixtureDef);
}

b2PolygonShape& EntityManager::getBodyShape() {
	return bodyShape;
}

b2BodyDef& EntityManager::getBodyDef() {
	return bodyDef;
}

b2FixtureDef& EntityManager::getBodyFixtureDef() {
	return bodyFixtureDef;
}

b2Body* EntityManager::getBody() {
	return body;
}

b2Fixture* EntityManager::getBodyFixture() {
	return bodyFixture;
}

EntityManager::~EntityManager()
{
}
