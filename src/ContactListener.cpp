#include "ContactListener.h"
#include "Player.h"
#include "RectangleEntity.h"
#include <iostream>

void ContactListener::BeginContact(b2Contact* contact) {
	auto* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	auto* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
	
	std::cout << typeid(bodyUserDataA).name() << "\n" << std::flush;

	/*if (bodyUserDataA && dynamic_cast<Player*>(bodyUserDataA))
		static_cast<Player*>(bodyUserDataA)->playerOnGround();

	if (bodyUserDataB)
		static_cast<Player*>(bodyUserDataB)->playerOnGround();*/
}

void ContactListener::EndContact(b2Contact* contact) {
	auto* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	auto* bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

	/*if (bodyUserDataA)
		static_cast<Player*>(bodyUserDataA)->playerInAir();

	if (bodyUserDataB)
		static_cast<Player*>(bodyUserDataB)->playerInAir();*/
}
