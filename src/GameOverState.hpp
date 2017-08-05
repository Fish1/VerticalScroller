#ifndef GAMEOVERSTATE_HPP
#define GAMEOVERSTATE_HPP

#include "State.hpp"

class UIElement;

class GameOverState : public State
{
private:

	UIElement * m_retryButton;

	UIElement * m_menuButton;

	UIElement * m_score;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	GameOverState(unsigned int score);

	~GameOverState();
	
	void update(float delta);
};

#endif
