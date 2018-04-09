#ifndef GUNBUILDER_HPP
#define GUNBUILDER_HPP

#include "Builder.hpp"

#include "Gun.hpp"

#include <functional>

class World;

class GunBuilder : public Builder
{
private:

	bool m_player = false;

	float m_fireRate;

	float m_bulletSpeed;

	World * m_world;

	std::function<void(float, World*, Gun*, bool)> m_fire;
	
	std::string m_soundSrc;

public:

	GunBuilder & setPlayer(bool player);

	GunBuilder & setFireRate(float fireRate);

	GunBuilder & setBulletSpeed(float bulletSpeed);

	GunBuilder & setWorld(World & world);

	GunBuilder & setFire(std::function<void(float, World*, Gun*, bool)> fire);
	
	GunBuilder & setSound(std::string soundSrc);

	GameObject * build();

};

#endif
