#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"

#include <vector>

class UIElement;

class MenuState : public State
{
private:

	UIElement * m_startButton;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	MenuState();

	~MenuState();

	void update(float delta);
};

#endif
