#include "EnemyFactory.hpp"

#include "EnemyBuilder.hpp"

#include <fstream>

EnemyFactory::EnemyFactory()
{
	/*
	 * "enemy1" should be the weakest an most basic of enemies
	 */

	EnemyBuilder * builder = new EnemyBuilder();

	builder->setHealth(1).setSpeed(250.0f).setTexture("enemy1");

	m_builders.insert(std::pair<std::string, EnemyBuilder*>("enemy1", builder));

	/*
	 * "enemy2" should be a bit faster but otherwise the
	 *  same as "enemy1"
	 */

	builder = new EnemyBuilder();

	builder->setHealth(1).setSpeed(320.0f).setTexture("enemy1");

	m_builders.insert(std::pair<std::string, EnemyBuilder*>("enemy2", builder));

	/*
	 * "enemy3" does stuff and it is blue :)
	 */

	builder = new EnemyBuilder();

	builder->setHealth(1).setSpeed(300.0f).setTexture("enemy2");

	m_builders.insert(std::pair<std::string, EnemyBuilder*>("enemy3", builder));

	/*
	 * "boss1" has more health but slower speed
	 */

	builder = new EnemyBuilder();

	builder->setHealth(20).setSpeed(100.0f).setTexture("boss1");

	m_builders.insert(std::pair<std::string, EnemyBuilder*>("boss1", builder));
}

void EnemyFactory::loadFromFile(std::string key, std::string filename)
{
	EnemyBuilder * builder = new EnemyBuilder();

	std::ifstream in(filename);

	std::string textureKey;
	int health; 
	float speed;

	in >> textureKey;
	in >> health;
	in >> speed;	

	builder->setHealth(health).setSpeed(speed).setTexture(textureKey);
}

GameObject * EnemyFactory::build(std::string key)
{
	return m_builders.at(key)->build();
}
