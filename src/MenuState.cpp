#include "MenuState.hpp"

#include "GameState.hpp"

#include "Define.hpp"

#include "Button.hpp"

#include <iostream>

MenuState::MenuState()
{
	std::cout << "Menu State" << std::endl;

	m_startButton = new Button("START", sf::Vector2f(720.0f / 2.0f, 720.0f / 2.0f));
}

MenuState::~MenuState()
{
	delete m_startButton;
}

void MenuState::update(float delta)
{
	m_startButton->update(delta);

	if(dynamic_cast<Button*>(m_startButton)->justClicked())
	{
		m_nextState = new GameState();	
	}
}

void MenuState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_startButton);
}
