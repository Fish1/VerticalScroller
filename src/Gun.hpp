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
	
	const float m_fireRate;

	const bool m_player = false;

	float m_lastFire = 0.0f;

	std::function<void(World*, Gun*)> m_fire;
	
	sf::Sound m_fireSound;

public:

	Gun(World & world, float fireRate, bool player, std::function<void(World*, Gun*)> fire, std::string soundSrc);

	void update(float delta);

	void fire();

	bool canFire() const;
};

#endif
