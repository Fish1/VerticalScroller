#include "StateManager.hpp"

#include "MenuState.hpp"

#include <iostream>

StateManager::StateManager()
{
	m_state = new MenuState();
		
	std::cout << " -- " << m_state << std::endl;
}

void StateManager::update(sf::RenderTarget & target)
{
	sf::Time time = m_clock.getElapsedTime();

	m_clock.restart();

	//m_state->update(time.asSeconds());

	m_state->update(0.01f < time.asSeconds() ? 0.01f : time.asSeconds());
	
	if(m_state != m_state->getNextState())
	{
		State * nextState = m_state->getNextState();
	
		std::cout << " -- " << nextState << std::endl;
		
		delete m_state;

		m_state = nextState;
	}

	target.clear();

	target.draw(*m_state);
}
