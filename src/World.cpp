#include "World.hpp"

#include <iostream>

#include "Spawner.hpp"

#include "GameObject.hpp"

#include "Player.hpp"

#include "Enemy.hpp"

#include "Bullet.hpp"

#include "TriGun.hpp"
#include "StandardGun.hpp"

#include "LevelDisplay.hpp"

World::World()
{
	m_spawner = new Spawner(m_enemies);
	
	m_spawner->loadFromFile("res/levels/level1.txt");

	m_player = new Player();

	dynamic_cast<Player*>(m_player)->setGun(new StandardGun(*this));

	m_levelDisplay = new LevelDisplay(m_spawner->getLevelName());
}

World::~World()
{
	delete m_player;

	delete m_spawner;

	for(GameObject * enemy : m_enemies)
	{
		delete enemy;
	}

	for(GameObject * bullet : m_bullets)
	{
		delete bullet;
	}
}

const Player * World::getPlayer()
{
	return dynamic_cast<Player*>(m_player);
}

void World::addEnemy(Enemy * enemy)
{
	m_enemies.push_back(enemy);
}

void World::addBullet(Bullet * bullet)
{
	m_bullets.push_back(bullet);
}

void World::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for(GameObject * enemy : m_enemies)
	{
		target.draw(*enemy);
	}

	for(GameObject * bullet : m_bullets)
	{
		target.draw(*bullet);
	}

	target.draw(*m_player);

	target.draw(*m_levelDisplay);
}

void World::update(float delta)
{
	m_levelDisplay->update(delta);

	m_spawner->update(delta);

	m_player->update(delta);

	for(GameObject * enemy : m_enemies)
	{
		enemy->update(delta);
	}

	for(GameObject * bullet : m_bullets)
	{
		bullet->update(delta);
	}

	updateCollision();

	if(m_enemies.size() == 0 && m_spawner->empty())
	{
		m_spawner->loadNextLevel();

		delete m_levelDisplay;

		m_levelDisplay = new LevelDisplay(m_spawner->getLevelName());
	}
}

void World::updateCollision()
{
	std::vector<GameObject *> deletePool;

	for(GameObject * enemy : m_enemies)
	{
		if(enemy->getPosition().y > 720.0f)
		{
			deletePool.push_back(enemy);
		}

		if(enemy->getGlobalBounds().intersects(m_player->getGlobalBounds()))
		{
			dynamic_cast<Player*>(m_player)->takeDamage(10.0f);
		}

		for(GameObject * bullet : m_bullets)
		{
			if(enemy->getGlobalBounds().intersects(bullet->getGlobalBounds()))
			{
				Enemy * enemyCast = dynamic_cast<Enemy*>(enemy);

				enemyCast->takeDamage(1.0f);
			
				if(enemyCast->getHealth() == 0)
				{
					deletePool.push_back(enemy);
				}	

				deletePool.push_back(bullet);
			}
		}
	}


	// Delete duplicates of objects. (If two bullets hit an enemy at the same time)
	{
		sort(deletePool.begin(), deletePool.end());

		deletePool.erase(unique(deletePool.begin(), deletePool.end()), deletePool.end());
	}

	for(GameObject * gameObject : deletePool)
	{
		for(unsigned int index = 0; index < m_enemies.size(); ++index)
		{
			if(m_enemies.at(index) == gameObject)
			{
				m_enemies.erase(m_enemies.begin() + index);

				break;
			}
		}

		for(unsigned int index = 0; index < m_bullets.size(); ++index)
		{
			if(m_bullets.at(index) == gameObject)
			{
				m_bullets.erase(m_bullets.begin() + index);

				break;
			}
		}

		delete gameObject;
	}
}
