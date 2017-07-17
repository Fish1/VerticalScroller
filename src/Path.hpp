#ifndef PATH_HPP
#define PATH_HPP

#include <vector>

#include <SFML/Graphics.hpp>

class Curve;

class Path
{
private:

	std::vector<sf::Vector2f> m_waypoints;

public:

	Path(std::vector<Curve *> curves, unsigned int split);

	sf::Vector2f getWaypoint();

	void update(sf::Vector2f currentPosition);
};

#endif
