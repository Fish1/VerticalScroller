#ifndef GUN_HPP
#define GUN_HPP

#include "GameObject.hpp"

#include "World.hpp"

#include "SoundBufferManager.hpp"

#include <functional>

#include <iostream>

class Gun : public GameObject
{
protected:

	World & m_world;

	float m_lastFire = 0.0f;

	const float m_fireRate;

	const bool m_player = false;

	std::function<void(World*, Gun*)> m_fire;
	
	sf::Sound m_fireSound;

public:

	Gun(World & world, float fireRate, bool player, std::function<void(World*, Gun*)> fire, std::string soundSrc = "") :
		m_world(world), m_fireRate(fireRate), m_player(player), m_fire(fire)
	{
		m_lastFire = m_fireRate;

		m_fireSound.setBuffer(SoundBufferManager::instance().get("galaga_shoot1"));

		m_fireSound.setVolume(10.0f);

		m_fireSound.setPitch(0.6f);
	}

	void update(float delta)
	{
		m_lastFire += delta;
	}

	bool canFire()
	{
		return m_lastFire > m_fireRate;
	}

	void fire()
	{
		if(m_lastFire < m_fireRate)
		{
			return;
		}

		m_lastFire = 0.0f;

		m_fire(&m_world, this);
		
		m_fireSound.play();
	}
};

#endif
