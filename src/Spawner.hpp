#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <vector>

#include <string>

class World;

class GameObject;

class SpawnElement;

class EnemyFactory;

class Spawner
{
private:

	EnemyFactory * m_enemyFactory;

	std::string m_nextLevel;

	std::string m_levelName;

	const float m_spawnRate = 1.0f;

	float m_lastSpawn = 0.0f;

	World & m_world;

	std::vector<SpawnElement *> m_spawnElements;

public:

	Spawner(World & world);

	void update(float delta);

	void loadFromFile(std::string filename);

	void loadNextLevel();

	std::string getLevelName();

	bool empty();
};

#endif
