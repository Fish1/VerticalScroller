#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

class World;

class GameState : public State
{
private:

	World * m_world;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:
	
	GameState();

	~GameState();

	void update(float delta);
};

#endif
