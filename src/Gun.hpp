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

	bool m_player = false;

public:

	Gun(World & world, float fireRate) :
		m_world(world), m_fireRate(fireRate)
	{
		m_lastFire = m_fireRate;	
	}

	void markPlayer()
	{
		m_player = true;
	}

	void update(float delta)
	{
		m_lastFire += delta;
	}

	virtual void fire() = 0;
};

#endif
