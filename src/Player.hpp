#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"

class Player : public GameObject
{
private:
	
	const float m_fireRate = 0.25f;

	const float m_speed = 400.0f;

public:

	Player();

	void update(float delta);

	float getFireRate();
};

#endif
