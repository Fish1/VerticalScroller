#include "Button.hpp"

#include "MouseManager.hpp"

#include "FontManager.hpp"

Button::Button(sf::Vector2f position, std::string text)
{
	sf::Font & font = FontManager::instance().get("Audiowide-Regular");

	m_text = new sf::Text();

	m_text->setFont(font);

	m_text->setString(text);

	m_text->setPosition(position);

	m_shape = new sf::RectangleShape();

	m_shape->setFillColor(sf::Color::Blue);

	updateSize();
}

Button::~Button()
{
	delete m_text;

	delete m_shape;
}

void Button::updateSize()
{
	sf::Vector2f size(m_text->getGlobalBounds().width + m_text->getCharacterSize(),
			m_text->getGlobalBounds().height);
	
	dynamic_cast<sf::RectangleShape*>(m_shape)->setSize(size);

	m_shape->setOrigin(m_shape->getGlobalBounds().width / 2.0f,
			m_shape->getGlobalBounds().height / 2.0f);

	m_shape->setPosition(m_text->getPosition() + sf::Vector2f(0.0f, m_text->getCharacterSize() / 2.0f));
	
	m_text->setOrigin(m_text->getGlobalBounds().width / 2.0f,
			m_text->getGlobalBounds().height / 2.0f);


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
	bool ret = false;

	if(m_shape->getGlobalBounds().contains(MouseManager::instance()->getPosition().x,
					MouseManager::instance()->getPosition().y))
	{
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == false && m_lmbClicked == true)
		{
			ret = true;
		}
	}
	
	m_lmbClicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	return ret;
}

void Button::setText(std::string text)
{
	m_text->setString(text);

	updateSize();
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_shape);
	
	target.draw(*m_text);
}
