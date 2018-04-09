#ifndef GUNFACTORY_HPP
#define GUNFACTORY_HPP

#include "Factory.hpp"

#include <functional>

class World;

class Gun;

class GunFactory : public Factory
{
private:

	std::map<std::string, std::function<void(float, World*, Gun*, bool)> > m_fireTypes;

	bool m_playerGuns;

public:

	GunFactory(World & world, bool playerGuns);

	void loadFromFile(std::string filename, World & world);

	virtual GameObject * build(std::string key);

private:

	void loadFireTypes(World & world);
};

#endif
