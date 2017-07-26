#include "GameOverState.hpp"

#include "GameState.hpp"

#include "Button.hpp"

#include <iostream>

GameOverState::GameOverState()
{
	std::cout << "Game Over State" << std::endl;

	m_retryButton = new Button("RETRY", sf::Vector2f(720.0f / 2.0f, 720.0f / 2.0f));
}

GameOverState::~GameOverState()
{
	delete m_retryButton;
}

void GameOverState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_retryButton);
}

void GameOverState::update(float delta)
{
	m_retryButton->update(delta);

	if(dynamic_cast<Button*>(m_retryButton)->justClicked())
	{
		m_nextState = new GameState();
	}
}
