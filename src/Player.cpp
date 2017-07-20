#include "Player.hpp"

#include "Define.hpp"

#include <iostream>

#include "TextureManager.hpp"

#include "Gun.hpp"

Player::Player()
{
	m_sprite = new sf::Sprite(TextureManager::instance().get("player"));

	m_sprite->rotate(-90.0f);

	m_sprite->setPosition(720.0f / 2.0f, 720.0f - 100.0f);

	m_sprite->setScale(2.0f, 2.0f);

	m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2.0f, m_sprite->getLocalBounds().height / 2.0f);
}

void Player::update(float delta)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_sprite->move(sf::Vector2f(0.0f, -1.0f) * m_speed * delta);
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_sprite->move(sf::Vector2f(0.0f, 1.0f) * m_speed * delta);
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sprite->move(sf::Vector2f(-1.0f, 0.0f) * m_speed  * delta);
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sprite->move(sf::Vector2f(1.0f, 0.0f) * m_speed * delta);
	}

	m_gun->update(delta);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_gun->setPosition(getPosition());

		m_gun->setRotation(getRotation());

		m_gun->fire();
	}
}

void Player::setGun(Gun * gun)
{
	m_gun = gun;
}

void Player::takeDamage(float damage)
{
	m_health -= damage;
}

float Player::getHealth() const
{
	return m_health;
}

float Player::getFireRate() const
{
	return m_fireRate;
}
