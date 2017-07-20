#include "EnemyFactory.hpp"

#include "EnemyBuilder.hpp"

EnemyFactory::EnemyFactory()
{
	EnemyBuilder * a = new EnemyBuilder();
	a->setHealth(1).setSpeed(250.0f).setTexture("enemy1");
	m_builders.insert(std::pair<std::string, EnemyBuilder*>("enemy1", a));
}

GameObject * EnemyFactory::build(std::string key)
{
	return m_builders.at(key)->build();
}
