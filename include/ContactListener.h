#ifndef CONTACT_LISTENER_H
#define CONTACT_LISTENER_H

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

class ContactListener : public b2ContactListener {
public:
	void BeginContact(b2Contact*);
	void EndContact(b2Contact*);
};

#endif // !CONTACT_LISTENER_H
