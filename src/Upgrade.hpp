#ifndef UPGRADE_HPP
#define UPGRADE_HPP

#include "GameObject.hpp"

class Player;

class World;

class Upgrade : public GameObject
{
private:

public:

	virtual void update(float delta);

	virtual void activate(Player * player, World * world) = 0;

};

#endif
