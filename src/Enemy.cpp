#include "Enemy.hpp"

#include <iostream>

#include <math.h>

#include "TextureManager.hpp"

#include "BezierCurve.hpp"
#include "LinearCurve.hpp"

#include "Define.hpp"

Enemy::Enemy(int health, float speed, Path * path, std::string texture) :
	m_health(health), m_speed(speed), m_path(path)
{
	m_sprite = new sf::Sprite(TextureManager::instance().get(texture));

	m_sprite->setScale(2.0f, 2.0f);
	
	m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2.0f, m_sprite->getLocalBounds().height / 2.0f);

	m_sprite->setPosition(m_path->getWaypoint().x, m_path->getWaypoint().y);
}

Enemy::~Enemy()
{
	delete m_path;

	m_path = nullptr;
}

void Enemy::update(float delta)
{
	m_path->update(m_sprite->getPosition());
	
	sf::Vector2f waypoint = m_path->getWaypoint();

	sf::Vector2f direction = waypoint - m_sprite->getPosition();

	float mag = sqrt((direction.x * direction.x) + (direction.y * direction.y));

	if(mag != 0.0f)
	{
		direction /= mag;

		direction *= m_speed * delta;

		m_sprite->move(direction);
	}

	float rotation = atan2(direction.y, direction.x);

	rotation *= 180.0f / PI;

	m_sprite->setRotation(rotation - 90.0f);

}

void Enemy::takeDamage()
{
	if(m_health != 0)
	{
		--m_health;
	}
}

int Enemy::getHealth()
{
	return m_health;
}
