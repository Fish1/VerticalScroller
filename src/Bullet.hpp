#ifndef BULLET_HPP
#define BULLET_HPP

#include "GameObject.hpp"

class Bullet : public GameObject
{
private:

	const float m_speed;

	sf::Vector2f m_direction;

public:

	Bullet(sf::Vector2f position, sf::Vector2f direction, float speed, sf::Texture & texture);

	void update(float delta);
};

#endif
