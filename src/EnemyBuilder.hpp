#ifndef ENEMYBUILDER_HPP
#define ENEMYBUILDER_HPP

#include "Builder.hpp"

#include <string>

class Gun;

class EnemyBuilder : public Builder
{
private:

	unsigned int m_health;

	float m_speed;

	std::string m_texture;

	Gun * m_gun = nullptr;

public:

	EnemyBuilder & setGun(Gun * gun);

	EnemyBuilder & setHealth(unsigned int health);

	EnemyBuilder & setSpeed(float speed);

	EnemyBuilder & setTexture(std::string texture);

	GameObject * build();
};

#endif
