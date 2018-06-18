#include "Player.hpp"

#include "Define.hpp"

#include "MouseManager.hpp"

#include "TextureManager.hpp"

#include "Gun.hpp"

#include "Math.hpp"

Player::Player()
{
	rotate(-90.0f);

	setPosition(sf::Vector2f(720.0f / 2.0f, 720.0f - 100.0f));

	enableCollision();

	setDebugColor(sf::Color::Green);

	setAnimation(TextureManager::instance().get("ship"),
	2, 1, 16, 16);
}

void Player::update(float delta)
{
	updateCollision();

	updateAnimation(delta);

	sf::Vector2i mouse = MouseManager::instance()->getPosition();

	sf::Vector2f direction = sf::Vector2f(mouse.x, mouse.y) - getPosition();

	float mag = sqrt((direction.x * direction.x) + (direction.y * direction.y));

	direction /= mag;

	if(mag > 3.0f)
	{
		move(direction * 500.0f * delta);
	}

	if(m_gun != nullptr)
	{
		m_gun->update(delta);
	
		if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			m_gun->setPosition(getPosition());

			m_gun->setRotation(getRotation());

			m_gun->fire(true);
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
