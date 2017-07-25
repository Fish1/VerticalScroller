#include "Button.hpp"

#include "MouseManager.hpp"

Button::Button(std::string text, sf::Vector2f position)
{
	m_font = new sf::Font();

	m_font->loadFromFile("res/fonts/Audiowide-Regular.ttf");

	m_text = new sf::Text();

	m_text->setFont(*m_font);

	m_text->setString(text);

	m_text->setPosition(position);

	m_text->setOrigin(m_text->getGlobalBounds().width / 2.0f,
			m_text->getGlobalBounds().height / 2.0f);

	sf::Vector2f size(m_text->getGlobalBounds().width + m_text->getCharacterSize(),
			m_text->getGlobalBounds().height);

	m_shape = new sf::RectangleShape(size);

	m_shape->setOrigin(m_shape->getGlobalBounds().width / 2.0f,
			m_shape->getGlobalBounds().height / 2.0f);

	m_shape->setPosition(m_text->getPosition() + sf::Vector2f(0.0f, m_text->getCharacterSize() / 2.0f));

	m_shape->setFillColor(sf::Color::Blue);
}

void Button::update(float delta)
{
	if(m_shape->getGlobalBounds().contains(MouseManager::instance()->getPosition().x,
					MouseManager::instance()->getPosition().y))
	{
		m_shape->setFillColor(sf::Color::Red);
	}
	else
	{
		m_shape->setFillColor(sf::Color::Blue);
	}
}

bool Button::justClicked()
{
	if(m_shape->getGlobalBounds().contains(MouseManager::instance()->getPosition().x,
					MouseManager::instance()->getPosition().y))
	{
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return true;
		}
	}

	return false;
}
