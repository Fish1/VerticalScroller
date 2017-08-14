#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

class State : public sf::Drawable
{
private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const
	{

	}

protected:
	
	State * m_nextState = nullptr;

public:

	State();

	/*
	 * 	The state manager should switch to the state
	 * 	that this function returns.
	 *
	 *	@return - A pointer to the next state (const)
	 */
	State * getNextState() const;

	/*
	 *	Update the relevent elements with keyboard input.
	 *
	 * 	@param1 - Updated keyboard input data.
	 *
	 *	@return - void
	 */
	virtual void updateText(sf::String text);

	/*
	 *	Update the relevent elements as the mouse wheel
	 *	is scrolled.
	 *
	 *	@param1 - Amount the mouse wheel was moved.
	 *
	 *	@return - void
	 */
	virtual void updateScroll(float delta);

	/*
	 *	Update the relevent elements with a timestep.
	 * 	
	 * 	@param1 - The timestep.
	 *
	 *	@return - void
	 */
	virtual void update(float delta) = 0;
};

#endif
