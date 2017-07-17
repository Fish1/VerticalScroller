#include "Bullet.hpp"

#include <iostream>

#include "TextureManager.hpp"

Bullet::Bullet(sf::Vector2f position)
{
	m_sprite = new sf::Sprite(TextureManager::instance().get("blueProjectile"));
	
	m_sprite->setPosition(position);

	m_sprite->setScale(1.0f, 1.0f);
	
	m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2.0f, m_sprite->getLocalBounds().height / 2.0f);
}

void Bullet::update(float delta)
{
	m_sprite->move(sf::Vector2f(0.0f, -1.0f) * delta * m_speed);
}
