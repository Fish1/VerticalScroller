#include "Player.hpp"

#include "Define.hpp"

#include "TextureManager.hpp"

#include "Gun.hpp"

#include "Define.hpp"

#include <iostream>

Player::Player()
{
	m_sprite = new sf::Sprite(TextureManager::instance().get("ship"));

	m_sprite->rotate(-90.0f);

	m_sprite->setPosition(720.0f / 2.0f, 720.0f - 100.0f);

	m_sprite->setScale(2.0f, 2.0f);

	m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2.0f, m_sprite->getLocalBounds().height / 2.0f);
}

void Player::update(float delta)
{
	sf::Vector2f direction(0.0f, 0.0f);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction += sf::Vector2f(0.0f, -1.0f);	
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction += sf::Vector2f(0.0f, 1.0f);	
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction += sf::Vector2f(-1.0f, 0.0f);
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction += sf::Vector2f(1.0f, 0.0f);
	}

	float mag = sqrt((direction.x * direction.x) + (direction.y * direction.y));

	direction /= mag;

	if(mag != 0.0f)
	{
		m_sprite->move(direction * 450.0f * delta);
	}

	if(m_gun != nullptr)
	{
		m_gun->update(delta);
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			m_gun->setPosition(getPosition());

			m_gun->setRotation(getRotation());

			m_gun->fire();
		}
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
