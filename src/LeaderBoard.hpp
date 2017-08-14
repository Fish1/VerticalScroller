#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include "UIElement.hpp"

class LeaderBoard : public UIElement
{
private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	std::vector<sf::Text*> m_rows;

public:

	LeaderBoard(float x, float y);

	~LeaderBoard();

	void scroll(float delta);

	void update(float delta);
};

#endif
