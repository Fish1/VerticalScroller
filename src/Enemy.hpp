#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "GameObject.hpp"

class Path;

class Gun;

class Enemy : public GameObject
{
private:

	const float m_speed;

	float m_health;

	Path * m_path = nullptr;

	Gun * m_gun = nullptr;

public:

	Enemy(float health, float speed, std::string texture);

	~Enemy();

	void setGun(Gun * gun);

	void setPath(Path * path);

	void update(float delta);

	void takeDamage(float damage);

	float getHealth();
};

#endif
