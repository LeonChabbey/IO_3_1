#ifndef UTILITIES_H
#define UTILITIES_H

#include <SFML/Graphics.hpp>
#include "json.hpp"
#include <string>

using json = nlohmann::json;

#define RATIO_PIXEL_METER 64.f

struct UserDataStruct {
	std::string className;
};

float pixel2meter(float pixel);
float meter2pixel(float meter);

sf::Color convertJsonToSfColor(json colorConfig);

#endif // !UTILITIES_H
