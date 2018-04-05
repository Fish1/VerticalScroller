#ifndef BULLETBUILDER_HPP
#define BULLETBUILDER_HPP

#include "Builder.hpp"

#include <SFML/Graphics.hpp>

class BulletBuilder : public Builder
{
private:

	sf::Texture * m_texture;

	sf::Vector2f m_position;

	sf::Vector2f m_direction;

	float m_speed;

public:

	BulletBuilder & setTexture(sf::Texture & texture);

	BulletBuilder & setPosition(sf::Vector2f position);

	BulletBuilder & setDirection(sf::Vector2f direction);

	BulletBuilder & setSpeed(float speed);

	virtual GameObject * build();
};

#endif
