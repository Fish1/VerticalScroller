#include "GameObject.hpp"

GameObject::GameObject()
{
	m_sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
	delete m_sprite;
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_sprite);
}

void GameObject::setTexture(sf::Texture & texture)
{
	m_sprite->setTexture(texture, true);
	
	m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2.0f, m_sprite->getLocalBounds().height / 2.0f);
	
	m_sprite->setScale(2.0f, 2.0f);
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

sf::FloatRect GameObject::getGlobalBounds() const
{
	return m_sprite->getGlobalBounds();
}
