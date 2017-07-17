#include "MenuState.hpp"

#include "GameState.hpp"

#include <iostream>

MenuState::MenuState()
{
	std::cout << "Init Menu State" << std::endl;

	m_nextState = new GameState();
}

MenuState::~MenuState()
{
	std::cout << "End Menu State" << std::endl;
}

void MenuState::update(float delta)
{

}

void MenuState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

}
