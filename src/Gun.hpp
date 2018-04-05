#ifndef GUN_HPP
#define GUN_HPP

#include "GameObject.hpp"

#include <functional>

#include <iostream>

class World;

class Gun : public GameObject
{
protected:

	World & m_world;
	
	const float m_fireRate;

	const float m_bulletSpeed;

	const bool m_player;

	float m_lastFire = 0.0f;

	std::function<void(float, World*, Gun*)> m_fire;
	
	sf::Sound m_fireSound;

public:

	Gun(World & world, float fireRate, float bulletSpeed, bool player, std::function<void(float, World*, Gun*)> fire, std::string soundSrc);

	void update(float delta);

	void fire();

	bool canFire() const;
};

#endif
