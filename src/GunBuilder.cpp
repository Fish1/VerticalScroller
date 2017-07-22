#include "GunBuilder.hpp"

#include "Gun.hpp"

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

GunBuilder & GunBuilder::setWorld(World * world)
{
	m_world = world;

	return *this;
}

GunBuilder & GunBuilder::setFire(std::function<void(World*, Gun*)> fire)
{
	m_fire = fire;

	return *this;
}

GameObject * GunBuilder::build()
{
	Gun * gun = new Gun(*m_world, m_fireRate, m_player, m_fire);

	return gun;
}
