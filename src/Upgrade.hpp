#ifndef UPGRADE_HPP
#define UPGRADE_HPP

#include "GameObject.hpp"

class Player;

class World;

class Upgrade : public GameObject
{
private:

public:

	/*
	 *	Update the state of the game object
	 *	with a timestep.
	 *
	 *	@param1 - The timestep.
	 *	@return - void
	 */
	virtual void update(float delta);

	/*
	 *	This function should be called when
	 *	the player collides with the upgrade.
	 *
	 *	@param1 - A reference to the player object
	 *	@param2 - A reference to the world in which
	 *		the collision happened.
	 *
	 *	@return - void
	 */
	virtual void activate(Player & player, World & world) = 0;

};

#endif
