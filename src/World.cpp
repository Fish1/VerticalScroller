#include "World.hpp"

#include <iostream>

#include "Spawner.hpp"

#include "GameObject.hpp"

#include "Player.hpp"

#include "Enemy.hpp"

#include "Bullet.hpp"

#include "Upgrade.hpp"

#include "TriGunUpgrade.hpp"

#include "LevelDisplay.hpp"

#include "GunBuilder.hpp"

#include "BulletBuilder.hpp"

#include "TextureManager.hpp"

#include "Math.hpp"

World::World()
{
	m_spawner = new Spawner(*this);
	
	m_spawner->loadFromFile("res/levels/level1.txt");

	m_player = new Player();

	m_levelDisplay = new LevelDisplay(m_spawner->getLevelName());

	Upgrade * upgrade = new TriGunUpgrade;
	
	upgrade->setPosition(sf::Vector2f(720.0f / 2.0f, 0.0f));

	m_upgrades.push_back(upgrade);

	GunBuilder gunBuilder;

	gunBuilder.setWorld(*this).setFireRate(0.07f).setPlayer(true).setSound("res/sound/galaga_shoot1.ogg");

	gunBuilder.setFire([](float bulletSpeed, World * world, Gun * gun, bool playerBullet)
	{
		float rotation = gun->getRotation() * (Math::PI / 180.0f);

		float x = cos(rotation);

		float y = sin(rotation);

		BulletBuilder bb;

		bb.setTexture(TextureManager::instance().get("smallprojectile_a"));
		bb.setPosition(gun->getPosition());
		bb.setDirection(sf::Vector2f(x, y));
		bb.setSpeed(600.0f);

		world->addBullet(dynamic_cast<Bullet*>(bb.build()), true);
	});

	dynamic_cast<Player*>(m_player)->setGun(dynamic_cast<Gun*>(gunBuilder.build()));
}

World::~World()
{
	delete m_levelDisplay;

	delete m_player;

	delete m_spawner;

	for(GameObject * enemy : m_enemies)
	{
		delete enemy;
	}

	for(GameObject * bullet : m_playerBullets)
	{
		delete bullet;
	}
	
	for(GameObject * bullet : m_enemyBullets)
	{
		delete bullet;
	}

	for(GameObject * upgrade : m_upgrades)
	{
		delete upgrade;
	}
}

// Provides outside access to the player.
const Player & World::getPlayer() const
{
	return *dynamic_cast<Player*>(m_player);
}

// Provides outside access to the players score.
unsigned int World::getScore() const
{
	return m_score;
}

// Adds an enemy to the world for it to be updated and rendered.
void World::addEnemy(Enemy * enemy)
{
	m_enemies.push_back(enemy);
}

// Adds a bullet to the world for it to be updated and rendered.
void World::addBullet(Bullet * bullet, bool playerBullet)
{
	if(playerBullet)
	{
		m_playerBullets.push_back(bullet);
	}
	else
	{
		m_enemyBullets.push_back(bullet);
	}
}

void World::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for(GameObject * bullet : m_playerBullets)
	{
		target.draw(*bullet);
	}

	for(GameObject * bullet : m_enemyBullets)
	{
		target.draw(*bullet);
	}
	
	for(GameObject * enemy : m_enemies)
	{
		target.draw(*enemy);
	}

	for(GameObject * upgrade : m_upgrades)
	{
		target.draw(*upgrade);
	}

	target.draw(*m_player);

	target.draw(*m_levelDisplay);
}

// Calls all of the other update functions.
void World::update(float delta)
{
	updateSpawner(delta);

	updateGameObjects(delta);

	updateCollision();

	updateDeletes();
}

// Loops through al lgame objects and updates them with a timestep.
void World::updateGameObjects(float delta)
{
	m_levelDisplay->update(delta);

	m_player->update(delta);

	for(GameObject * enemy : m_enemies)
	{
		enemy->update(delta);
	}

	for(GameObject * bullet : m_playerBullets)
	{
		bullet->update(delta);
	}

	for(GameObject * bullet : m_enemyBullets)
	{
		bullet->update(delta);
	}

	for(GameObject * upgrade : m_upgrades)
	{
		upgrade->update(delta);
	}
}

// Updates the spawner with the proper timestep. It will also load a new
// spawner after the current level is finished.
void World::updateSpawner(float delta)
{
	m_spawner->update(delta);

	if(m_enemies.size() == 0 && m_spawner->empty())
	{
		m_spawner->loadNextLevel();

		delete m_levelDisplay;

		m_levelDisplay = new LevelDisplay(m_spawner->getLevelName());
	}

	// if there are no more levels to load
	// kill the player to end the game ez
	
	if(gameOver())
	{
		dynamic_cast<Player*>(m_player)->takeDamage(999999.0f);
	}
}

// Loops through game objects to detect collisions and determine
// proper action after collision
void World::updateCollision()
{
	for(GameObject * upgrade : m_upgrades)
	{
		if(upgrade->intersects(*m_player))
		{
			Player * player = dynamic_cast<Player*>(m_player);

			dynamic_cast<Upgrade*>(upgrade)->activate(*player, *this);
		}
	}

	for(GameObject * bullet : m_enemyBullets)
	{
		if(bullet->getPosition().y > 720.0f || bullet->getPosition().y < 0.0f ||
				bullet->getPosition().x > 720.0f || bullet->getPosition().x < 0.0f)
		{
			bullet->markDelete();
		}

		if(bullet->intersects(*m_player))
		{
			dynamic_cast<Player*>(m_player)->takeDamage(10.0f);

			bullet->markDelete();
		}
	}

	for(GameObject * enemy : m_enemies)
	{
		if(enemy->getPosition().y > 720.0f)
		{
			enemy->markDelete();
		}

		if(enemy->intersects(*m_player))
		{
			dynamic_cast<Player*>(m_player)->takeDamage(10.0f);
		}

		for(GameObject * bullet : m_playerBullets)
		{
			if(bullet->getPosition().y > 720.0f || bullet->getPosition().y < 0.0f ||
					bullet->getPosition().x > 720.0f || bullet->getPosition().x < 0.0f)
			{
				bullet->markDelete();
			}

			if(enemy->intersects(*bullet))
			{
				Enemy * enemyCast = dynamic_cast<Enemy*>(enemy);

				enemyCast->takeDamage(1.0f);
				
				if(enemyCast->getHealth() == 0)
				{
					enemy->markDelete();

					m_score += 1;
				}

				bullet->markDelete();
			}
		}
	}
}

// Loops through and polls each game object to see if it is requesting
// to be deleted. If so, then it will remove that object from the
// world.
void World::updateDeletes()
{
	for(unsigned int index = 0; index < m_enemies.size(); ++index)
	{
		GameObject * enemy = m_enemies.at(index);

		if(enemy->getDelete())
		{
			m_enemies.erase(m_enemies.begin() + index);

			delete enemy;

			--index;
		}
	}

	for(unsigned int index = 0; index < m_playerBullets.size(); ++index)
	{
		GameObject * bullet = m_playerBullets.at(index);

		if(bullet->getDelete())
		{
			m_playerBullets.erase(m_playerBullets.begin() + index);

			delete bullet;

			--index;
		}
	}
	
	for(unsigned int index = 0; index < m_enemyBullets.size(); ++index)
	{
		GameObject * bullet = m_enemyBullets.at(index);

		if(bullet->getDelete())
		{
			m_enemyBullets.erase(m_enemyBullets.begin() + index);

			delete bullet;

			--index;
		}
	}

	for(unsigned int index = 0; index < m_upgrades.size(); ++index)
	{
		GameObject * upgrade = m_upgrades.at(index);

		if(upgrade->getDelete())
		{
			m_upgrades.erase(m_upgrades.begin() + index);

			delete upgrade;

			--index;
		}
	}
}

// If this returns true the player has beat the game
// Returns true if there are no enemies on the screen,
// no enemies left in the spawner,
// and if there is not another level to be loaded.
bool World::gameOver()
{
	return m_enemies.size() == 0 && 
		m_spawner->empty() && 
		m_spawner->isNextLevel() == false;
}
