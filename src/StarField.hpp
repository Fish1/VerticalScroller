#ifndef STARFIELD_HPP
#define STARFIELD_HPP

#include <SFML/Graphics.hpp>

class Star;

class StarField : public sf::Drawable
{
private:

	std::vector<Star *> m_stars;

	float m_lastCreation = 0.0f;

private:

	void updateCreation(float delta);

	void updateMovement(float delta);

public:

	StarField();

	void update(float delta);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

#endif
