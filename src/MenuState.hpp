#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"

#include <vector>

class UIElement;

class MenuState : public State
{
private:

	UIElement * m_startButton = nullptr;

	UIElement * m_registerButton = nullptr;

	UIElement * m_loginButton = nullptr;

	UIElement * m_logoutButton = nullptr;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	MenuState();

	~MenuState();

	void updateInput(sf::String text);

	void update(float delta);
};

#endif
