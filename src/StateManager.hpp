#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include "State.hpp"

#include "SFML/Graphics.hpp"

class StateManager
{
private:

	sf::Clock m_clock;

	State * m_state;

public:

	StateManager();

	void update(sf::RenderTarget & target);
};

#endif
