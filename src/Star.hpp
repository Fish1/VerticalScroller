#ifndef STAR_HPP
#define STAR_HPP

#include "GameObject.hpp"

class Star : public GameObject
{
private:

	float m_speed;

	void createColor();

public:

	Star();

	void update(float delta);

};

#endif
