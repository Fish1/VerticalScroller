#include "MenuState.hpp"

#include "GameState.hpp"

#include "Define.hpp"

#include <iostream>

MenuState::MenuState()
{
	std::cout << "Menu State" << std::endl;

	e = dynamic_cast<Enemy*>(ef.build("boss1"));

	e->setPosition(sf::Vector2f(500.0f, 500.0f));

	s = new sf::CircleShape(3.0f);

	s->setFillColor(sf::Color::Green);

	s->setPosition(sf::Vector2f(500.0f, 500.0f));

	p = new Player();
}

MenuState::~MenuState()
{
	delete s;

	delete e;

	delete p;
}

void MenuState::update(float delta)
{
	//m_nextState = new GameState();

	e->rotate(10.0f * delta);
	
	e->update(delta);

	p->update(delta);

	if(e->intersects(*p))
	{
		e->setDebugColor(sf::Color::Red);
		p->setDebugColor(sf::Color::Red);
	}
	else
	{
		e->setDebugColor(sf::Color::Green);
		p->setDebugColor(sf::Color::Green);
	}
}

void MenuState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*e);

	target.draw(*p);
}
