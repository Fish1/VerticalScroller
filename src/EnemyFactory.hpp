#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

#include "Factory.hpp"

class EnemyFactory : public Factory
{
public:

	EnemyFactory();

	void loadFromFile(std::string filename);

	virtual GameObject * build(std::string key);
};

#endif
