#ifndef GAMEOVERSTATE_HPP
#define GAMEOVERSTATE_HPP

#include "State.hpp"

class UIElement;

class GameOverState : public State
{
private:

	UIElement * m_retryButton;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	GameOverState();

	~GameOverState();
	
	void update(float delta);
};

#endif
