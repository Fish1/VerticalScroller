#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"

#include "Player.hpp"

#include "Enemy.hpp"

#include "EnemyFactory.hpp"

class MenuState : public State
{
private:

	EnemyFactory ef;
	
	Player * p;

	Enemy * e;

	sf::Shape * s;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	MenuState();

	~MenuState();

	void update(float delta);
};

#endif
