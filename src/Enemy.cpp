#include "Enemy.hpp"

#include <iostream>

#include <math.h>

#include "TextureManager.hpp"

#include "Path.hpp"

#include "CubicCurve.hpp"

#include "LinearCurve.hpp"

#include "Gun.hpp"

#include "Math.hpp"

#include "GunBuilder.hpp" 

Enemy::Enemy(float health, float speed, std::string texture) :
	m_speed(speed), m_health(health)
{
	setTexture(TextureManager::instance().get(texture));

	enableCollision();

	setDebugColor(sf::Color::Red);
}

Enemy::~Enemy()
{
	delete m_path;
}

void Enemy::setGun(Gun * gun)
{
	m_gun = gun;
}

void Enemy::setPath(Path * path)
{
	m_path = path;

	setPosition(sf::Vector2f(m_path->getWaypoint().x, m_path->getWaypoint().y));
}

void Enemy::update(float delta)
{
	updateCollision();

	if(m_path != nullptr)
	{
		m_path->update(getPosition());
		
		sf::Vector2f waypoint = m_path->getWaypoint();

		sf::Vector2f direction = waypoint - getPosition();

		float mag = sqrt((direction.x * direction.x) + (direction.y * direction.y));

		// Move the GameObject towards the next waypoint

		if(mag != 0.0f)
		{
			direction /= mag;

			direction *= m_speed * delta;

			move(direction);
		}

		// Rotate the GameObject towards the next waypoint

		float rotation = atan2(direction.y, direction.x);

		rotation *= 180.0f / Math::PI;

		setRotation(rotation);
	}
	
	if(m_gun != nullptr)
	{
		m_gun->update(delta);

		m_gun->setPosition(getPosition());

		m_gun->setRotation(getRotation());

		m_gun->fire(false);
	}
}

void Enemy::takeDamage(float damage)
{
	m_health -= damage;
}

float Enemy::getHealth()
{
	return m_health;
}
