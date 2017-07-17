#include "GameState.hpp"

#include <iostream>

#include "Player.hpp"

#include "Enemy.hpp"

#include "Bullet.hpp"

GameState::GameState()
{
	std::cout << "Init Game State" << std::endl;

	m_spawner = new Spawner(m_enemies);

	m_spawner->loadFromFile("res/level1.txt");

	m_nextState = this;

	m_player = new Player();
}

GameState::~GameState()
{
	std::cout << "End Game State" << std::endl;

	delete m_spawner;

	delete m_player;

	for(GameObject * object : m_enemies)
	{
		delete object;
	}
	
	for(GameObject * object : m_bullets)
	{
		delete object;
	}
}

void GameState::update(float delta)
{
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

	m_lastFire += delta;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_lastFire > ((Player*) m_player)->getFireRate())
	{
		m_bullets.push_back(new Bullet(m_player->getPosition() - sf::Vector2f(12.0f, 10.0f)));
		
		m_bullets.push_back(new Bullet(m_player->getPosition() - sf::Vector2f(-12.0f, 10.0f)));

		m_lastFire = 0.0f;
	}

	updateCollision();
}

void GameState::updateCollision()
{
	std::vector<GameObject *> deletePool;

	for(GameObject * enemy : m_enemies)
	{
		if(enemy->getPosition().y > 720.0f)
		{
			deletePool.push_back(enemy);
		}

		for(GameObject * bullet : m_bullets)
		{
			if(enemy->getGlobalBounds().intersects(bullet->getGlobalBounds()))
			{
				Enemy * enemyCast = dynamic_cast<Enemy*>(enemy);

				enemyCast->takeDamage();
			
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

void GameState::draw(sf::RenderTarget & target, sf::RenderStates states) const
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
}
