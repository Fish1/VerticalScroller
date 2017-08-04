#ifndef PATH_HPP
#define PATH_HPP

#include <vector>

#include <SFML/Graphics.hpp>

class Curve;

class Path
{
private:

	std::vector<sf::Vector2f> m_waypoints;

	unsigned int m_waypoint = 0;

public:

	Path(std::vector<Curve *> curves, unsigned int split);

	sf::Vector2f getWaypoint() const;

	void update(sf::Vector2f currentPosition);
};

#endif
