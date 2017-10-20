#ifndef UTILITIES_H
#define UTILITIES_H

#include <SFML/Graphics.hpp>
#include "json.hpp"

using json = nlohmann::json;

#define RATIO_PIXEL_METER 64.f

float pixel2meter(float pixel);
float meter2pixel(float meter);

sf::Color convertJsonToSfColor(json colorConfig);

#endif // !UTILITIES_H
