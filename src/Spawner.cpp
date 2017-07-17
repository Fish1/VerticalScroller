#include "Spawner.hpp"

#include "EnemyBuilder.hpp"

#include "SpawnElement.hpp"

#include "Path.hpp"

#include "BezierCurve.hpp"

#include "LinearCurve.hpp"

#include <fstream>

#include <iostream>

Spawner::Spawner(std::vector<GameObject *> & gameObjects) :
	m_gameObjects(gameObjects)
{

}

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
		EnemyBuilder builder;

		GameObject * enemy = builder.setHealth(2).setSpeed(150.0f).setPath(spawnElement->getPath()).
			setTexture("enemy1").build();

		m_gameObjects.push_back(enemy);

		m_lastSpawn = 0.0f;

		delete spawnElement;

		m_spawnElements.erase(m_spawnElements.begin());
	}
}

void Spawner::loadFromFile(std::string filename)
{
	std::ifstream in;

	in.open(filename);

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

				BezierCurve * b = new BezierCurve(lastPoint, point1, point2, point3);

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
