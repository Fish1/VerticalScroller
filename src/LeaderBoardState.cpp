#include "LeaderBoardState.hpp"

#include "MenuState.hpp"

#include "Button.hpp"

#include "LeaderBoard.hpp"

#include <iostream>

LeaderBoardState::LeaderBoardState()
{
	std::cout << "Leader Board State" << std::endl;

	m_backButton = new Button(sf::Vector2f(720.0f / 2.0f, 720.0f / 2.0f), "BACK");

	m_leaderBoard = new LeaderBoard(50.0f, 50.0f);
}

LeaderBoardState::~LeaderBoardState()
{
	delete m_backButton;

	delete m_leaderBoard;
}

void LeaderBoardState::updateScroll(float delta)
{
	dynamic_cast<LeaderBoard*>(m_leaderBoard)->scroll(delta);	
}

void LeaderBoardState::update(float delta)
{
	m_backButton->update(delta);

	if(dynamic_cast<Button*>(m_backButton)->justClicked())
	{
		m_nextState = new MenuState();
	}

	m_leaderBoard->update(delta);
}

void LeaderBoardState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_backButton);

	target.draw(*m_leaderBoard);
}
