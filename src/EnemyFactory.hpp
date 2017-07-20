#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

#include "Factory.hpp"

class EnemyFactory : public Factory
{
public:

	EnemyFactory();

	virtual GameObject * build(std::string key);
};

#endif
