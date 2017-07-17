#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "GameObject.hpp"

#include "Path.hpp"

class Enemy : public GameObject
{
private:

	const float m_speed;

	int m_health;

	Path * m_path;

public:

	Enemy(int health, float speed, Path * path, std::string texture);

	~Enemy();

	void update(float delta);

	void takeDamage();

	int getHealth();
};

#endif
