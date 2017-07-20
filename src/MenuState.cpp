#include "MenuState.hpp"

#include "GameState.hpp"

#include <iostream>

MenuState::MenuState()
{
	std::cout << "Menu State" << std::endl;
}

MenuState::~MenuState()
{

}

void MenuState::update(float delta)
{
	m_nextState = new GameState();
}

void MenuState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

}
