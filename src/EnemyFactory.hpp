#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

#include "Factory.hpp"

class GunFactory;

class World;

class EnemyFactory : public Factory
{
public:

	EnemyFactory();

	void loadFromFile(std::string filename, World & world, GunFactory & gunFactory);

	virtual GameObject * build(std::string key);
};

#endif
