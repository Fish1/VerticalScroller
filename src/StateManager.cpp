#include "StateManager.hpp"

#include "MenuState.hpp"

StateManager::StateManager()
{
	m_state = new MenuState();
}

void StateManager::update(sf::RenderTarget & target)
{
	sf::Time time = m_clock.getElapsedTime();

	m_clock.restart();

	m_state->update(time.asSeconds());
	
	if(m_state != m_state->getNextState())
	{
		State * nextState = m_state->getNextState();

		delete m_state;

		m_state = nextState;
	}

	target.clear();

	target.draw(*m_state);
}
