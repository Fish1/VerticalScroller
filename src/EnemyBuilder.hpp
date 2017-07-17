#ifndef ENEMYBUILDER_HPP
#define ENEMYBUILDER_HPP

#include "Builder.hpp"

#include <string>

class Path;

class EnemyBuilder : public Builder
{
private:

	unsigned int m_health;

	float m_speed;

	Path * m_path;

	std::string m_texture;

public:

	EnemyBuilder & setHealth(unsigned int health);

	EnemyBuilder & setSpeed(float speed);

	EnemyBuilder & setPath(Path * path);

	EnemyBuilder & setTexture(std::string texture);

	GameObject * build();
};

#endif
