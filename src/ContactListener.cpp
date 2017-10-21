#include "ContactListener.h"
#include "Player.h"
#include "RectangleEntity.h"
#include <iostream>
#include <utilities.h>


void ContactListener::BeginContact(b2Contact* contact) {
	auto* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();

	UserDataStruct* structGottenA = (UserDataStruct*)bodyUserDataA;

	std::cout << "begin A:" << structGottenA->className << "\n" << std::flush;

	if(structGottenA->className == "Player")
		static_cast<Player*>(bodyUserDataA)->playerOnGround();
}

void ContactListener::EndContact(b2Contact* contact) {
	auto* bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();

	UserDataStruct* structGottenA = (UserDataStruct*)bodyUserDataA;

	std::cout << "end A:" << structGottenA->className << "\n" << std::flush;

	if (structGottenA->className == "Player")
		static_cast<Player*>(bodyUserDataA)->playerInAir();
}
