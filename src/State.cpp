#include "State.hpp"

State::State()
{
	m_nextState = this;
}

// The state manager should switch to the state that
// this function returns.
State * State::getNextState() const
{
	return m_nextState;
}

// Update the relevent elements with keyboard input.
void State::updateText(sf::String text)
{

}

// Update the relevent elements as the mouse wheel
// is scrolled.
void State::updateScroll(float delta)
{

}
