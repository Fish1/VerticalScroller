#ifndef CURVE_HPP
#define CURVE_HPP

#include <SFML/Graphics.hpp>

class Curve
{
private:

public:

	virtual sf::Vector2f calculatePoint(float time) = 0;

};

#endif
