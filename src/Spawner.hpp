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

	bool m_isNextLevel = false;

	World & m_world;

	std::vector<SpawnElement *> m_spawnElements;

public:

	Spawner(World & world);

	/*
	 *	Determine when to spawn new GameObjects.
	 *
	 *	@param1 - The timestep.
	 *
	 *	@return - void
	 */
	void update(float delta);

	/*
	 *	Read a file and fill the SpawnElement vector
	 *	with the proper objects.
	 *
	 *	@param1 - The level that should be loaded.
	 *
	 *	@return - void
	 */
	void loadFromFile(std::string filename);

	/*
	 *	The first file that is loaded should indicate
	 *	the next file that should be loaded. This function
	 *	will load that file.
	 *
	 *	@param - none
	 *
	 *	@return - void
	 */
	void loadNextLevel();

	std::string getLevelName();

	/*
	 *	To indicate if there are more GameObjects that need to spawn.
	 *
	 *	@param - none
	 *
	 *	@return - Boolean that indicates that there are no more GameObjects
	 *	that need to spawn.
	 */
	bool empty();

	/*
	 *	To indicate if there is another level to load after this.
	 *	The level file should have end to indicate that there
	 *	is not another level to load.
	 *
	 *	@param - none
	 *
	 *	@return - Boolean that indicates that there are no more
	 *	levels to load.
	 */
	bool isNextLevel();
};

#endif
