#ifndef GUNFACTORY_HPP
#define GUNFACTORY_HPP

#include "Factory.hpp"

class World;

class GunFactory : public Factory
{
public:

	GunFactory(World & world);
	
	virtual GameObject * build(std::string key);

};

#endif
