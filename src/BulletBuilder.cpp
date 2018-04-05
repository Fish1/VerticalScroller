#include "BulletBuilder.hpp"

#include "Bullet.hpp"

GameObject * BulletBuilder::build()
{
	return new Bullet(m_position, m_direction, m_speed, *m_texture);
}

BulletBuilder & BulletBuilder::setTexture(sf::Texture & texture)
{
	m_texture = &texture;

	return *this;
}

BulletBuilder & BulletBuilder::setPosition(sf::Vector2f position)
{
	m_position = position;

	return *this;
}

BulletBuilder & BulletBuilder::setDirection(sf::Vector2f direction)
{
	m_direction = direction;

	return *this;
}

BulletBuilder & BulletBuilder::setSpeed(float speed)
{
	m_speed = speed;

	return *this;
}
