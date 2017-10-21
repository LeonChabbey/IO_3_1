#ifndef PLATFORMS_MANAGER_H
#define PLATFORMS_MANAGER_H

#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include <vector>
#include <RectangleEntity.h>

#include "json.hpp"

using json = nlohmann::json;

class PlatformsManager {
private:
	sf::RenderWindow* window;
	std::vector<RectangleEntity> platforms;
public:
	PlatformsManager(sf::RenderWindow*, b2World*, json, json);

	void update();
	void draw();

	~PlatformsManager();
};


#endif // !PLATFORMS_MANAGER_H
