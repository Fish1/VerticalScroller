#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"

class MenuState : public State
{
private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	MenuState();

	~MenuState();

	void update(float delta);
};

#endif
