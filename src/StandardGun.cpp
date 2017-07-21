#include "StandardGun.hpp"

#include "Bullet.hpp"

#include "Define.hpp"

StandardGun::StandardGun(World & world) :
	Gun(world, 0.25f)
{

}

void StandardGun::fire()
{
	if(m_lastFire < m_fireRate)
	{
		return;
	}

	m_lastFire = 0.0f;

	float rotation = getRotation() * (PI / 180.0f);

	float x = cos(rotation);

	float y = sin(rotation);

	Bullet * bullet = new Bullet(getPosition(), sf::Vector2f(x, y));

	if(m_player)
	{
		m_world.addPlayerBullet(bullet);
	}
	else
	{
		m_world.addEnemyBullet(bullet);
	}
}
