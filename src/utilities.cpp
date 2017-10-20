#include <utilities.h>

float pixel2meter(float a) {
	return a / RATIO_PIXEL_METER;
}

float meter2pixel(float a) {
	return a * RATIO_PIXEL_METER;
}

sf::Color convertJsonToSfColor(json colorConfig) {
	return sf::Color((int8_t)colorConfig[0], (int8_t)colorConfig[1], (int8_t)colorConfig[2]);
}
