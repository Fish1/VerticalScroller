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

	float m_lastFire = 0.0f;

	std::function<void(float, World*, Gun*, bool)> m_fire;
	
	sf::Sound m_fireSound;

public:

	Gun(World & world, float fireRate, float bulletSpeed, std::function<void(float, World*, Gun*, bool)> fire, std::string soundSrc);

	void update(float delta);

	void fire(bool playerBullet);

	bool canFire() const;
};

#endif
