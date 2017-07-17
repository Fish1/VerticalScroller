#ifndef BEZIERCURVE_HPP
#define BEZIERCURVE_HPP

#include "Curve.hpp"

class BezierCurve : public Curve
{
private:

	sf::Vector2f m_point1;

	sf::Vector2f m_point2;
	
	sf::Vector2f m_point3;

	sf::Vector2f m_point4;

public:

	BezierCurve(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4);

	sf::Vector2f calculatePoint(float time);

};

#endif
