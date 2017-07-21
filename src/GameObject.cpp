#include "GameObject.hpp"

GameObject::GameObject()
{
	m_sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
	if(m_sprite != nullptr)
	{
		delete m_sprite;

		m_sprite = nullptr;
	}
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if(m_sprite != nullptr)
	{
		target.draw(*m_sprite);
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

void GameObject::setPosition(sf::Vector2f position)
{
	if(m_sprite != nullptr)
	{
		m_sprite->setPosition(position);
	}
}

sf::Vector2f GameObject::getPosition() const
{
	if(m_sprite != nullptr)
	{
		return m_sprite->getPosition();
	}

	return sf::Vector2f(0.0f, 0.0f);
}

void GameObject::setRotation(float rotation)
{
	if(m_sprite != nullptr)
	{
		m_sprite->setRotation(rotation);
	}
}

float GameObject::getRotation() const
{
	if(m_sprite != nullptr)
	{
		return m_sprite->getRotation();
	}

	return 0.0f;
}

sf::FloatRect GameObject::getGlobalBounds() const
{
	if(m_sprite != nullptr)
	{
		return m_sprite->getGlobalBounds();
	}

	return sf::FloatRect();
}
