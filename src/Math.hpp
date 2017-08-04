#ifndef MATH_HPP
#define MATH_HPP

#include <cmath>

#include <SFML/Graphics.hpp>

namespace Math
{
	const float PI = 3.14159265359;

	float magnitude(sf::Vector2f vector);

	float theta(sf::Vector2f vector);

	sf::Vector2f normalize(sf::Vector2f vector);

	sf::Vector2f projectPoint(sf::Vector2f point, sf::Vector2f axis);
};

#endif
