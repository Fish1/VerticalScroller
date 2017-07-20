#include "LevelDisplay.hpp"

LevelDisplay::LevelDisplay(std::string text)
{
	m_font = new sf::Font();

	m_font->loadFromFile("res/fonts/Audiowide-Regular.ttf");

	m_text = new sf::Text(text, *m_font);

	m_text->setCharacterSize(50);

	sf::FloatRect r = m_text->getGlobalBounds();

	m_text->setPosition(sf::Vector2f(-r.width, 250.0f));
}

LevelDisplay::~LevelDisplay()
{
	delete m_font;

	delete m_text;
}

void LevelDisplay::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_text);
}

void LevelDisplay::update(float delta)
{
	sf::FloatRect r = m_text->getGlobalBounds();

	if(r.left < 720.0f)
	{
		m_text->move(sf::Vector2f(275.0f, 0.0f) * delta);
	}
}
