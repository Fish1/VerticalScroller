 #include "EnemyFactory.hpp"

#include "EnemyBuilder.hpp"

#include <iostream>

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

	builder->setHealth(1).setSpeed(400.0f).setTexture("enemy2");

	m_builders.insert(std::pair<std::string, EnemyBuilder*>("enemy3", builder));

	/*
	 * "boss1" has more health but slower speed
	 */

	builder = new EnemyBuilder();

	builder->setHealth(20).setSpeed(100.0f).setTexture("boss1");

	m_builders.insert(std::pair<std::string, EnemyBuilder*>("boss1", builder));

	m_builders.clear();
}

void EnemyFactory::loadFromFile(std::string filename)
{
	std::cout << "Loading Enemies..." << std::endl;
	std::ifstream in(filename);

	std::string name;
	std::string texture;
	unsigned int health;
	unsigned int speed;

	while(in >> name >> texture >> health >> speed)
	{
		EnemyBuilder * builder = new EnemyBuilder();
	
		builder->setHealth(health).setSpeed(speed).setTexture(texture);
	
		m_builders.insert(std::pair<std::string, EnemyBuilder*>(name, builder));

		std::cout << " -- " << name << std::endl;
	}

}

GameObject * EnemyFactory::build(std::string key)
{
	return m_builders.at(key)->build();
}
