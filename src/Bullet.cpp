#include "Bullet.hpp"

#include <iostream>

#include <math.h>

#include "TextureManager.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction)
{
	m_sprite = new sf::Sprite(TextureManager::instance().get("blueprojectile"));
	
	m_sprite->setPosition(position);

	m_sprite->setScale(1.0f, 1.0f);
	
	m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2.0f, m_sprite->getLocalBounds().height / 2.0f);

	float mag = sqrt((direction.x * direction.x) + (direction.y * direction.y));

	direction /= mag;

	m_direction = direction;
}

void Bullet::update(float delta)
{
	m_sprite->move(sf::Vector2f(m_direction.x, m_direction.y) * delta * m_speed);
}
