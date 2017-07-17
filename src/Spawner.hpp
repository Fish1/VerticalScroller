#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <vector>

#include <stdlib.h>

#include <string>

class GameObject;

class SpawnElement;

class Spawner
{
private:

	const float m_spawnRate = 1.0f;

	float m_lastSpawn = 0.0f;

	std::vector<GameObject *> & m_gameObjects;	

	std::vector<SpawnElement *> m_spawnElements;

public:

	Spawner(std::vector<GameObject *> & gameObjects);

	void update(float delta);

	void loadFromFile(std::string filename);

};

#endif
