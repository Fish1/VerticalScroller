#include "GameObject.hpp"

#include "Collision.hpp"

#include "Animation.hpp"

#include "Define.hpp"

#include <iostream>

GameObject::GameObject()
{
	m_sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
	delete m_sprite;

	if(m_animation != nullptr)
	{
		delete m_animation;
	}

	if(m_collision != nullptr)
	{
		delete m_collision;
	}
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	m_sprite->setTexture(m_animation->getTexture());

	target.draw(*m_sprite);

	if(g_debug == true && m_collision != nullptr)
	{
		target.draw(*m_collision);
	}
}

void GameObject::setAnimation(sf::Texture & texture)
{
	if(m_animation != nullptr)
	{
		delete m_animation;
	}

	m_animation = new Animation(texture, 0, 0, 0, 0);
	

}

void GameObject::setAnimation(sf::Texture & texture,
unsigned int sheetWidth, unsigned int sheetHeight, 
unsigned int width, unsigned int height)
{
	if(m_animation != nullptr)
	{
		delete m_animation;
	}

	m_animation = new Animation(texture, sheetWidth, sheetHeight, width, height);
}

void GameObject::setAnimationDuration(float duration)
{
	m_animation->setDuration(duration);
}

void GameObject::enableCollision()
{
	if(m_collision == nullptr)
	{
		m_collision = new Collision(*this);
	}
}

void GameObject::updateAnimation(float delta)
{
	if(m_animation != nullptr)
	{
		m_animation->update(delta);
		
		m_sprite->setTexture(m_animation->getTexture(), true);
		
		m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2.0f, m_sprite->getLocalBounds().height / 2.0f);
	}
}

void GameObject::setDebugColor(sf::Color color)
{
	m_collision ->setCornerColor(color);
}

void GameObject::updateCollision()
{
	if(m_collision != nullptr)
	{
		m_collision->update();
	}
}

void GameObject::update(float delta)
{
	
}

void GameObject::markDelete()
{
	m_delete = true;
}

bool GameObject::getDelete()
{
	return m_delete;
}

void GameObject::move(sf::Vector2f move)
{
	m_sprite->move(move);
}

void GameObject::setPosition(sf::Vector2f position)
{
	m_sprite->setPosition(position);
}

sf::Vector2f GameObject::getPosition() const
{
	return m_sprite->getPosition();
}

void GameObject::rotate(float rotation)
{
	m_sprite->rotate(rotation);
}

void GameObject::setRotation(float rotation)
{
	m_sprite->setRotation(rotation);
}

float GameObject::getRotation() const
{
	return m_sprite->getRotation();
}

void GameObject::setScale(sf::Vector2f scale)
{
	m_sprite->setScale(scale);
}

sf::Vector2f GameObject::getScale() const
{
	return m_sprite->getScale();
}

void GameObject::setColor(sf::Color color)
{
	m_sprite->setColor(color);
}

sf::Color GameObject::getColor() const
{
	return m_sprite->getColor();
}

sf::FloatRect GameObject::getGlobalBounds() const
{
	return m_sprite->getGlobalBounds();
}

sf::FloatRect GameObject::getLocalBounds() const
{
	return m_sprite->getLocalBounds();
}

bool GameObject::intersects(GameObject & other) const
{
	if(m_collision != nullptr)
	{
		return m_collision->intersects(*other.m_collision);
	}

	return false;
}
