#include "GameState.hpp"

#include <iostream>

#include "GameOverState.hpp"

#include "World.hpp"

#include "Player.hpp"

#include "Bullet.hpp"

GameState::GameState()
{
	std::cout << "Game State" << std::endl;

	m_world = new World();
}

GameState::~GameState()
{
	delete m_world;
}

void GameState::update(float delta)
{
	m_world->update(delta);

	if(m_world->getPlayer()->getHealth() <= 0.0f)
	{
		m_nextState = new GameOverState();
	}
}

void GameState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_world);
}
