#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

#include <vector>

#include "Spawner.hpp"

class GameObject;

class GameState : public State
{
private:

	Spawner * m_spawner;

	float m_lastFire = 0.0f;

	GameObject * m_player = nullptr;

	std::vector<GameObject *> m_enemies;

	std::vector<GameObject *> m_bullets;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	void updateCollision();

public:
	
	GameState();

	~GameState();

	void update(float delta);

};

#endif
