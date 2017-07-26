#include "Bullet.hpp"

#include <iostream>

#include "Define.hpp"

#include "TextureManager.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction)
{
	setTexture(TextureManager::instance().get("blueprojectile"));

	setPosition(position);

	setRotation(atan2(direction.y, direction.x) * (180.0f / PI));

	enableCollision();

	setDebugColor(sf::Color::White);

	float mag = sqrt((direction.x * direction.x) + (direction.y * direction.y));

	direction /= mag;

	m_direction = direction;
}

void Bullet::update(float delta)
{
	move(sf::Vector2f(m_direction.x, m_direction.y) * delta * m_speed);

	updateCollision();
}
