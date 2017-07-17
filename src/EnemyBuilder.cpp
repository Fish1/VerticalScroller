#include "EnemyBuilder.hpp"

#include "Enemy.hpp"

GameObject * EnemyBuilder::build()
{
	Enemy * enemy = new Enemy(m_health, m_speed, m_path, m_texture);

	return enemy;
}

EnemyBuilder & EnemyBuilder::setHealth(unsigned int health)
{
	m_health = health;

	return *this;
}

EnemyBuilder & EnemyBuilder::setSpeed(float speed)
{
	m_speed = speed;

	return *this;
}

EnemyBuilder & EnemyBuilder::setPath(Path * path)
{
	m_path = path;

	return *this;
}

EnemyBuilder & EnemyBuilder::setTexture(std::string texture)
{
	m_texture = texture;

	return *this;
}
