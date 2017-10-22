#include "ContactListener.h"
#include "Player.h"
#include "RectangleEntity.h"
#include <iostream>
#include <utilities.h>


void ContactListener::BeginContact(b2Contact* contact) {
	auto* bodyUserDataA = contact->GetFixtureA()->GetUserData();
	auto* bodyUserDataB = contact->GetFixtureB()->GetUserData();

	UserDataStruct* structGottenA = (UserDataStruct*)bodyUserDataA;
	UserDataStruct* structGottenB = (UserDataStruct*)bodyUserDataB;

	//std::cout << "begin A:" << structGottenA->className << "\n" << std::flush;
	//std::cout << "begin B:" << structGottenB->className << "\n" << std::flush;

	if (structGottenA->className == "PlayerFoot")
		static_cast<Player*>(structGottenA->instance)->playerOnGround();


	if (structGottenB->className == "PlayerFoot")
		static_cast<Player*>(structGottenB->instance)->playerOnGround();
}

void ContactListener::EndContact(b2Contact* contact) {
	auto* bodyUserDataA = contact->GetFixtureA()->GetUserData();
	auto* bodyUserDataB = contact->GetFixtureB()->GetUserData();

	UserDataStruct* structGottenA = (UserDataStruct*)bodyUserDataA;
	UserDataStruct* structGottenB = (UserDataStruct*)bodyUserDataB;

	//std::cout << "end A:" << structGottenA->className << "\n" << std::flush;
	//std::cout << "end B:" << structGottenB->className << "\n" << std::flush;
	

	if (structGottenA->className == "PlayerFoot")
		static_cast<Player*>(structGottenA->instance)->playerInAir();


	if (structGottenB->className == "PlayerFoot")
		static_cast<Player*>(structGottenB->instance)->playerInAir();
}
