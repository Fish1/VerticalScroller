#include "CubicCurve.hpp"

CubicCurve::CubicCurve(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4) :
	m_point1(point1), m_point2(point2), m_point3(point3), m_point4(point4)
{

}

sf::Vector2f CubicCurve::calculatePoint(float time)
{
	float tt = time * time;

	float ttt = tt * time;

	float u = 1.0f - time;

	float uu = u * u;

	float uuu = uu * u;

	sf::Vector2f point = 
		(uuu * m_point1) + (3 * uu * time * m_point2) + (3 * u * tt * m_point3) + (ttt * m_point4);

	return point;

}
