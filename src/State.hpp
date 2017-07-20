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

	State * getNextState() const;

	virtual void update(float delta) = 0;
};

#endif
