#include "GunBuilder.hpp"

GunBuilder & GunBuilder::setPlayer(bool player)
{
	m_player = player;

	return *this;
}

GunBuilder & GunBuilder::setFireRate(float fireRate)
{
	m_fireRate = fireRate;

	return *this;
}

GunBuilder & GunBuilder::setBulletSpeed(float bulletSpeed)
{
	m_bulletSpeed = bulletSpeed;

	return *this;
}

GunBuilder & GunBuilder::setWorld(World & world)
{
	m_world = &world;

	return *this;
}

GunBuilder & GunBuilder::setFire(std::function<void(float, World*, Gun*)> fire)
{
	m_fire = fire;

	return *this;
}

GunBuilder & GunBuilder::setSound(std::string soundSrc)
{
	m_soundSrc = soundSrc;
	
	return *this;
}

GameObject * GunBuilder::build()
{
	Gun * gun = new Gun(*m_world, m_fireRate, m_bulletSpeed, m_player, m_fire, m_soundSrc);

	return gun;
}
