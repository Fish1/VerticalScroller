#include "LinearCurve.hpp"

#include <iostream>

LinearCurve::LinearCurve(sf::Vector2f point1, sf::Vector2f point2) :
	m_point1(point1), m_point2(point2)
{

}

sf::Vector2f LinearCurve::calculatePoint(float time)
{
	sf::Vector2f point =
		m_point1 + 
		(time * (m_point2 - m_point1));

	return point;
}
