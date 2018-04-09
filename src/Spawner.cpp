#include "Spawner.hpp"

#include "EnemyFactory.hpp"
#include "EnemyBuilder.hpp"
#include "Enemy.hpp"

#include "SpawnElement.hpp"

#include "Path.hpp"

#include "CubicCurve.hpp"

#include "LinearCurve.hpp"

#include "GunFactory.hpp"

#include "GunBuilder.hpp"
#include "BulletBuilder.hpp"

#include "TextureManager.hpp"

#include "Math.hpp"

#include "World.hpp"

#include <fstream>

#include <iostream>

Spawner::Spawner(World & world) :
	m_world(world)
{
	m_enemyFactory = new EnemyFactory();
	m_gunFactory = new GunFactory(world, false);

	m_gunFactory->loadFromFile("res/guns/guns.txt", world);
	m_enemyFactory->loadFromFile("res/entities/enemies.txt", world, *m_gunFactory);
}

// Determine when to spawn new GameObjects.
void Spawner::update(float delta)
{
	if(m_spawnElements.size() <= 0)
	{
		return;
	}

	m_lastSpawn += delta;
	
	SpawnElement * spawnElement = m_spawnElements.at(0);

	if(m_lastSpawn > spawnElement->getDelta())
	{

		Enemy * enemy = dynamic_cast<Enemy*>(m_enemyFactory->build(spawnElement->getType()));

		enemy->setPath(spawnElement->getPath());
		
		enemy->setGun(dynamic_cast<Gun*>(m_gunFactory->build("single_500_1")));

		m_world.addEnemy(enemy);

		m_lastSpawn = 0.0f;

		delete spawnElement;

		m_spawnElements.erase(m_spawnElements.begin());
	}
}

// Read a file and fill the SpawnElement vector with the proper objects.
void Spawner::loadFromFile(std::string filename)
{
	std::ifstream in;

	in.open(filename);

	std::getline(in, m_levelName);

	std::getline(in, m_nextLevel);

	if(m_nextLevel == "end")
	{
		m_isNextLevel = false;
	}

	m_nextLevel = "res/levels/" + m_nextLevel;

	float delta;

	std::string type;
		
	std::string curvetype;

	float x, y;

	sf::Vector2f lastPoint;

	while(in >> delta >> type >> x >> y)
	{
		std::vector<Curve *> curves;

		lastPoint = sf::Vector2f(x, y);

		while(in >> curvetype)
		{
			if(curvetype.compare("#") == 0)
			{
				break;
			}

			if(curvetype.compare("cubic") == 0)
			{
				float x1, y1, x2, y2, x3, y3;

				in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

				sf::Vector2f point1(x1, y1);

				sf::Vector2f point2(x2, y2);

				sf::Vector2f point3(x3, y3);

				CubicCurve * b = new CubicCurve(lastPoint, point1, point2, point3);

				curves.push_back(b);

				lastPoint = point3;

			}
			else if(curvetype.compare("linear") == 0)
			{
				float x1, y1;

				in >> x1 >> y1;

				sf::Vector2f point1(x1, y1);

				LinearCurve * l = new LinearCurve(lastPoint, point1);

				curves.push_back(l);

				lastPoint = point1;
			}
		}
		
		Path * path = new Path(curves, 50);

		for(Curve * curve : curves)
		{
			delete curve;
		}

		SpawnElement * element = new SpawnElement(delta, type, path);
		
		m_spawnElements.push_back(element);
	}
}

// The first file that is loaded should indicate the next file that should be loaded.
// This function will load that file.
void Spawner::loadNextLevel()
{
	loadFromFile(m_nextLevel);
}

std::string Spawner::getLevelName()
{
	return m_levelName;
}

// To indicate if there are more GameObjects that need to spawn.
bool Spawner::empty()
{
	return m_spawnElements.size() == 0;
}


// To indicate if there is another level to load after this one.
bool Spawner::isNextLevel()
{
	return m_isNextLevel;
}
