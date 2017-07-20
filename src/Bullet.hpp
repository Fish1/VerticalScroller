#ifndef BULLET_HPP
#define BULLET_HPP

#include "GameObject.hpp"

class Bullet : public GameObject
{
private:

	const float m_speed = 400.0f;

	sf::Vector2f m_direction;

public:

	Bullet(sf::Vector2f position, sf::Vector2f direction);

	void update(float delta);
};

#endif
