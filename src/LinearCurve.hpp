#ifndef LINEARCURVE_HPP
#define LINEARCURVE_HPP

#include "Curve.hpp"

class LinearCurve : public Curve
{
private:

	sf::Vector2f m_point1;

	sf::Vector2f m_point2;

public:

	LinearCurve(sf::Vector2f point1, sf::Vector2f point2);

	sf::Vector2f calculatePoint(float time);

};

#endif
