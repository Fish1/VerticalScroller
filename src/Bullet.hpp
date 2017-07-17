#ifndef BULLET_HPP
#define BULLET_HPP

#include "GameObject.hpp"

class Bullet : public GameObject
{
private:

	const float m_speed = 400.0f;

public:

	Bullet(sf::Vector2f position);

	void update(float delta);
};

#endif
