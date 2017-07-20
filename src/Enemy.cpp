#include "Enemy.hpp"

#include <iostream>

#include <math.h>

#include "TextureManager.hpp"

#include "Path.hpp"

#include "CubicCurve.hpp"

#include "LinearCurve.hpp"

#include "Gun.hpp"

#include "Define.hpp"

Enemy::Enemy(float health, float speed, std::string texture) :
	m_health(health), m_speed(speed)
{
	m_sprite = new sf::Sprite(TextureManager::instance().get(texture));

	m_sprite->setScale(2.0f, 2.0f);
	
	m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2.0f, m_sprite->getLocalBounds().height / 2.0f);
}

Enemy::~Enemy()
{
	delete m_path;
}

void Enemy::setPath(Path * path)
{
	m_path = path;

	m_sprite->setPosition(m_path->getWaypoint().x, m_path->getWaypoint().y);
}

void Enemy::update(float delta)
{
	if(m_path == nullptr)
	{
		std::cout << "Warning - Enemy path not set" << std::endl;

		return;
	}

	m_path->update(m_sprite->getPosition());
	
	sf::Vector2f waypoint = m_path->getWaypoint();

	sf::Vector2f direction = waypoint - m_sprite->getPosition();

	float mag = sqrt((direction.x * direction.x) + (direction.y * direction.y));

	// Move the GameObject towards the next waypoint

	if(mag != 0.0f)
	{
		direction /= mag;

		direction *= m_speed * delta;

		m_sprite->move(direction);
	}

	// Rotate the GameObject towards the next waypoint

	float rotation = atan2(direction.y, direction.x);

	rotation *= 180.0f / PI;

	m_sprite->setRotation(rotation);

}

void Enemy::takeDamage(float damage)
{
	m_health -= damage;
}

float Enemy::getHealth()
{
	return m_health;
}
