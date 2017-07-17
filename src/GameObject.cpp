#include "GameObject.hpp"

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

sf::Vector2f GameObject::getPosition()
{
	if(m_sprite != nullptr)
	{
		return m_sprite->getPosition();
	}

	return sf::Vector2f(0.0f, 0.0f);
}

sf::FloatRect GameObject::getGlobalBounds()
{
	if(m_sprite != nullptr)
	{
		return m_sprite->getGlobalBounds();
	}

	return sf::FloatRect();
}
