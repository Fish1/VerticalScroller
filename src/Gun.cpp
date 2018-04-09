#include "Gun.hpp"

#include "SoundBufferManager.hpp"

Gun::Gun(World & world, float fireRate, float bulletSpeed, std::function<void(float, World *, Gun*, bool)> fire, std::string sound) :
	m_world(world), m_fireRate(fireRate), m_bulletSpeed(bulletSpeed), m_fire(fire) 
{
	m_lastFire = m_fireRate;

	m_fireSound.setBuffer(SoundBufferManager::instance().get("galaga_shoot1"));

	m_fireSound.setVolume(10.0f);

	m_fireSound.setPitch(0.6f);
}

void Gun::update(float delta)
{
	m_lastFire += delta;
}

void Gun::fire(bool playerBullet)
{
	if(m_lastFire < m_fireRate)
	{
		return;
	}

	m_lastFire = 0.0f;

	m_fire(m_bulletSpeed, &m_world, this, playerBullet);
	
	m_fireSound.play();
}

bool Gun::canFire() const
{
	return m_lastFire > m_fireRate;
}
