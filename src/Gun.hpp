#ifndef GUN_HPP
#define GUN_HPP

#include "GameObject.hpp"

#include "World.hpp"

class Gun : public GameObject
{
protected:

	World & m_world;

	float m_lastFire = 0.0f;

	const float m_fireRate;

public:

	Gun(World & world, float fireRate) :
		m_world(world), m_fireRate(fireRate)
	{
		m_lastFire = m_fireRate;	
	}

	void update(float delta)
	{
		m_lastFire += delta;
	}

	virtual void fire() = 0;
};

#endif
