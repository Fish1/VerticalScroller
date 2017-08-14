#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <SFML/Graphics.hpp>

class State;

class StateManager
{
private:

	sf::Clock m_clock;

	State * m_state;

public:

	StateManager();

	~StateManager();

	/*
	 *	Send the keyboard input to the current state
	 *
	 *	@param1 - the input data
	 *	@return - void
	 */
	void updateText(sf::String text);

	/*
	 *	Send the mouse wheel scroll to the current state.
	 *
	 *	@param1 - Offset of how much the mouse wheel
	 *	was scrolled.
	 *
	 *	@return - void
	 *
	 */
	void updateScroll(float scroll);

	/*
	 *	Update and render the current state
	 *	
	 *	@param1 - the target to render the state to
	 *	@return - void
	 */
	void update(sf::RenderTarget & target);
};

#endif
