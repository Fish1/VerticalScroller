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

	void updateGameObjects(float delta);

	void updateSpawner(float delta);

	void updateCollision();

	void updateDeletes();

public:

	World();

	~World();

	void update(float delta);

	const Player & getPlayer() const;

	unsigned int getScore() const;

	void addEnemy(Enemy * enemy);

	void addPlayerBullet(Bullet * bullet);

	void addEnemyBullet(Bullet * bullet);
};

#endif
