#include "..\include\PlatformsManager.h"
#include "utilities.h"
#include <iostream>

PlatformsManager::PlatformsManager(sf::RenderWindow* newWindow, b2World* world, json windowConfig, json platformsConfig) {
	window = newWindow;

	for (auto platform : platformsConfig) {
		const float POS_X = rand() % ((int)windowConfig["width"] - (int)platform["width"]);
		const float POS_Y = rand() % ((int)windowConfig["height"] - (int)platform["height"]);
		const sf::Color PLATFORM_COLOR = convertJsonToSfColor(platform["color"]);

		Platform newPlatform(world, platform["width"], platform["height"], POS_X, POS_Y, PLATFORM_COLOR, b2_staticBody);
		platforms.push_back(newPlatform);
	}
}

void PlatformsManager::update() {
	for (Platform& platform : platforms) {
		platform.update();
	}
}

void PlatformsManager::draw() {
	for (auto platform : platforms) {
		platform.draw(*window);
	}
}

PlatformsManager::~PlatformsManager() 
{
}
