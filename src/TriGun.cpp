#include "TriGun.hpp"

#include "Define.hpp"

#include "Bullet.hpp"

TriGun::TriGun(World & world) :
	Gun(world, 0.5f)
{

}

void TriGun::fire()
{
	if(m_lastFire < m_fireRate)
	{
		return;
	}

	m_lastFire = 0.0f;

	float rotationA = getRotation() * (PI / 180.0f);

	float xA = cos(rotationA);
	float yA = sin(rotationA);
	
	Bullet * bulletA = new Bullet(getPosition(), sf::Vector2f(xA, yA));

	float rotationB = rotationA - (5.0f * (PI / 180.0f));

	float xB = cos(rotationB);
	float yB = sin(rotationB);
	
	Bullet * bulletB = new Bullet(getPosition(), sf::Vector2f(xB, yB));

	float rotationC = rotationA + (5.0f * (PI / 180.0f));

	float xC = cos(rotationC);
	float yC = sin(rotationC);

	Bullet * bulletC = new Bullet(getPosition(), sf::Vector2f(xC, yC));

	if(m_player)
	{
		m_world.addPlayerBullet(bulletA);
		m_world.addPlayerBullet(bulletB);
		m_world.addPlayerBullet(bulletC);
	}
	else
	{
		m_world.addEnemyBullet(bulletA);
		m_world.addEnemyBullet(bulletB);
		m_world.addEnemyBullet(bulletC);
	}
}
