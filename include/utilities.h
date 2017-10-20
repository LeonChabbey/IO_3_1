#ifndef UTILITIES_H
#define UTILITIES_H

#define RATIO_PIXEL_METER 64.f

float pixel2meter(float a)
{
	return a / RATIO_PIXEL_METER;
}

float meter2pixel(float a)
{
	return a * RATIO_PIXEL_METER;
}

#endif // !UTILITIES_H
