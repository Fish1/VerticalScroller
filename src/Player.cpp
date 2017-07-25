#include "Player.hpp"

#include "Define.hpp"

#include "MouseManager.hpp"

#include "TextureManager.hpp"

#include "Gun.hpp"

#include "Define.hpp"

Player::Player()
{
	setTexture(TextureManager::instance().get("ship"));
	
	rotate(-90.0f);

	setPosition(sf::Vector2f(720.0f / 2.0f, 720.0f - 100.0f));

	enableRotationRectangle();

	setDebugColor(sf::Color::Green);
}

void Player::update(float delta)
{
	updateRotationRectangle();

	sf::Vector2i mouse = MouseManager::instance()->getPosition();

	sf::Vector2f direction = sf::Vector2f(mouse.x, mouse.y) - getPosition();

	float mag = sqrt((direction.x * direction.x) + (direction.y * direction.y));

	direction /= mag;

	if(mag != 0.0f)
	{
		move(direction * 400.0f * delta);
	}

	if(m_gun != nullptr)
	{
		m_gun->update(delta);
	
		if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
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
