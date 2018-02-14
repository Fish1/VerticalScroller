#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>

#include <vector>

class GameObject;

class Enemy;

class Bullet;

class Player;

class Spawner;

class LevelDisplay;

class World : public sf::Drawable
{
private:

	unsigned int m_score = 0;

	Spawner * m_spawner = nullptr;

	GameObject * m_player = nullptr;

	LevelDisplay * m_levelDisplay = nullptr;
		
	std::vector<GameObject *> m_enemies;

	std::vector<GameObject *> m_enemyBullets;

	std::vector<GameObject *> m_playerBullets;

	std::vector<GameObject *> m_upgrades;

private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	/*
	 *	Loops through all game objects
	 *	and updates them with a time step.
	 *
	 *	@param1 - The time step.
	 *	@return - void
	 */
	void updateGameObjects(float delta);

	/*
	 *	Updates the spawner with the proper
	 *	time-step. If will also load a new spawner
	 *	after the current level is finished.
	 *
	 *	@param1 - The time step.
	 *	@return - void
	 */
	void updateSpawner(float delta);

	/*
	 *	Loops through game objects to
	 *	detect collisions and determine proper
	 *	action after a collision.
	 *
	 *	@param - none
	 *	@return - void
	 */
	void updateCollision();

	/*
	 *	Loops through game object vectors polling
	 *	each object to see if it is requesting
	 *	to be deleted from the world. It will then
	 *	be deleted if it is.
	 *
	 *	@param - none
	 *	@return - void
	 */
	void updateDeletes();

public:

	World();

	~World();

	/*
	 *	Calls all other update functions.
	 *
	 *	@param1 - The time-step.
	 *	
	 *	@return - void
	 */
	void update(float delta);

	/*
	 *	Provides outside acces to the player.
	 *
	 *	@param - none
	 *
	 *	@return - A const reference to the player
	 *	that is being updated and rendered in 
	 *	the world. This player cannot be altered.
	 */
	const Player & getPlayer() const;

	/*
	 *	Provides outside access to the players
	 *	score.
	 *
	 *	@param - none
	 *
	 *	@return - The score that the player
	 *	has acheived.
	 */
	unsigned int getScore() const;

	/*
	 *	Adds an enemy to the world for
	 *	it to be updated and rendered.
	 *
	 *	@param1 - The enemy to be added
	 *	to the m_enemies vector.
	 *
	 *	@return - void
	 */
	void addEnemy(Enemy * enemy);

	/*
	 * 	Adds a bullet to the world for it to
	 * 	be update and rendered. This bullet 
	 * 	will not harm the players ship.
	 *
	 *	@param1 - The bullet to be added
	 *	to the m_playerBullets vector.
	 *
	 *	@return - void
	 */
	void addPlayerBullet(Bullet * bullet);

	/*
	 * 	Adds a bullet to the world for it to be updated
	 * 	and rendered. This bullet will not harm
	 * 	any enemy ship.
	 *
	 *	@param1 - the bullet that to be added 
	 *	to the m_enemyBullets vector.
	 *
	 *	@return - void
	 */
	void addEnemyBullet(Bullet * bullet);

	/*
	 *	If this returns true then the player has beat the
	 *	game. Will return true if there are no enemies on 
	 *	the scree, if there are no enemies in the spawner
	 *	and if there are no more levels to load.
	 *
	 *	@return - boolean, the player has beat the game
	 */
	bool gameOver();
};

#endif
