#ifndef LEADERBOARDSTATE_HPP
#define LEADERBOARDSTATE_HPP

#include "State.hpp"

class UIElement;

class LeaderBoardState : public State
{
private:

	UIElement * m_backButton = nullptr;

	UIElement * m_leaderBoard = nullptr;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	LeaderBoardState();

	~LeaderBoardState();

	void updateScroll(float delta);

	void update(float delta);
};

#endif
