#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"

class Gun;

class Player : public GameObject
{
private:

	Gun * m_gun = nullptr;

	float m_health = 1.0f;

	float m_lastFire = 0.0f;

	const float m_fireRate = 0.25f;

	const float m_speed = 400.0f;

public:

	Player();

	void update(float delta);

	void setGun(Gun * gun);

	void takeDamage(float damage);

	float getHealth() const;

	float getFireRate() const;
};

#endif
