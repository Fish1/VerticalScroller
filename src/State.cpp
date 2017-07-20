#include "State.hpp"

State::State()
{
	m_nextState = this;
}

State * State::getNextState() const
{
	return m_nextState;
}
