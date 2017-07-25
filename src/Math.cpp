#include "Math.hpp"

#include <math.h>

#include <iostream>

float Math::magnitude(sf::Vector2f vector)
{
	return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

float Math::theta(sf::Vector2f vector)
{
	return atan2(vector.y, vector.x);
}

sf::Vector2f Math::normalize(sf::Vector2f vector)
{
	return vector /= magnitude(vector);
}

sf::Vector2f Math::projectPoint(sf::Vector2f point, sf::Vector2f axis)
{
	float slopeAxis = axis.y / axis.x;

	float slopePerp = axis.x / axis.y * -1.0f;

	float bPerp = point.y - slopePerp * point.x;

	float x = bPerp / (slopeAxis - slopePerp);

	float y = slopeAxis * x;

	if(isinf(slopeAxis))
	{
		x = 0.0f;
		y = point.y;
	}
	
	if(isinf(slopePerp))
	{
		x = point.x;
		y = 0.0f;
	}

	return sf::Vector2f(x, y);
}
