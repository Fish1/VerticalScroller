#include "EnemyFactory.hpp"

#include "EnemyBuilder.hpp"

#include "GunFactory.hpp"

#include "Gun.hpp"

#include <iostream>

#include <fstream>

EnemyFactory::EnemyFactory()
{

}

void EnemyFactory::loadFromFile(std::string filename, World & world, GunFactory & gunFactory)
{
	std::cout << "Loading Enemies..." << std::endl;
	std::ifstream in(filename);

	std::string name;
	std::string texture;
	unsigned int health;
	unsigned int speed;
	std::string gunType;

	while(in >> name >> texture >> health >> speed >> gunType)
	{
		std::cout << " -- " << name << std::endl;

		EnemyBuilder * builder = new EnemyBuilder();
	
		builder->setHealth(health).setSpeed(speed).setTexture(texture);
		builder->setGun(dynamic_cast<Gun*>(gunFactory.build(gunType)));

		m_builders.insert(std::pair<std::string, EnemyBuilder*>(name, builder));
	}
}

GameObject * EnemyFactory::build(std::string key)
{
	return m_builders.at(key)->build();
}
