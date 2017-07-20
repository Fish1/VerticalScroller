#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <string>

#include <map>

class Builder;

class GameObject;

class Factory
{
protected:

	std::map<std::string, Builder*> m_builders;

public:

	virtual GameObject * build(std::string key) = 0;
};

#endif
