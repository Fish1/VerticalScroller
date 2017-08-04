#include "Path.hpp"

#include "Curve.hpp"

#include <iostream>

Path::Path(std::vector<Curve *> curves, unsigned int split)
{
	for(Curve * curve : curves)
	{
		for(unsigned int index = 0; index <= split; ++index)
		{
			sf::Vector2f waypoint = curve->calculatePoint((float)index / split);

			m_waypoints.push_back(waypoint);
		}
	}
}

sf::Vector2f Path::getWaypoint() const
{
	return m_waypoints.at(m_waypoint);
}

void Path::update(sf::Vector2f currentPosition)
{
	sf::Vector2f nextWaypoint = getWaypoint();

	float distance = ((currentPosition.x - nextWaypoint.x) * (currentPosition.x - nextWaypoint.x))
		+ ((currentPosition.y - nextWaypoint.y) * (currentPosition.y - nextWaypoint.y));

	if(distance < 10.0f)
	{
		m_waypoint += 1;

		if(m_waypoint == m_waypoints.size())
		{
			m_waypoint = 0;
		}
	}
}
