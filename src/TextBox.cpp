#include "TextBox.hpp"

#include "MouseManager.hpp"

#include "FontManager.hpp"

TextBox::TextBox(sf::Vector2f position, std::string label)
{
	sf::Font & font = FontManager::instance().get("mono");

	m_text = new sf::Text();

	m_text->setFont(font);

	m_text->setString("");

	m_text->setPosition(position + sf::Vector2f(5.0f, 0.0f));

	m_box = new sf::RectangleShape();

	resizeBox();

	m_box->setPosition(position);

	m_box->setFillColor(sf::Color::Black);

	m_box->setOutlineColor(sf::Color::White);

	m_box->setOutlineThickness(2.0f);

	m_blinker = new sf::RectangleShape();

	m_label = new sf::Text();

	m_label->setFont(font);

	m_label->setString(label);

	m_label->setPosition(position - sf::Vector2f(0.0f, m_label->getCharacterSize() + 10.0f));
}

TextBox::~TextBox()
{
	delete m_blinker;

	delete m_label;

	delete m_box;

	delete m_text;
}

// Remove the last character that was inserted into the TextBox.
void TextBox::truncate()
{
	std::string s = m_text->getString().toAnsiString();

	if(s.size() > 0)
	{
		s.pop_back();

		m_text->setString(s);
	}
}

// Reshape the TextBox as the user types into it.
void TextBox::resizeBox()
{
	sf::Vector2f size(m_text->getGlobalBounds().width + 34.0f, 50.0f);

	dynamic_cast<sf::RectangleShape*>(m_box)->setSize(size);
}

// Set the state of the TextBox so that when the user types, the text is
// inserted into this TextBox.
void TextBox::activate()
{
	m_active = true;		

	m_blinkTime = 0.5f;

	m_blink = false;
}

// Set the state of the TextBox so that when ther user types, the text is
// not inserted into this TextBox.
void TextBox::deactivate()
{
	m_active = false;

	m_blinkTime = 0.5f;

	m_blink = true;
}

// When the TextBox is active, the blinker will blink and indicate that
// this TextBox is active.
void TextBox::updateBlinker(float delta)
{
	m_blinkTime += delta;

	if(m_blinkTime >= 0.5f)
	{
		m_blink = !m_blink;

		m_blinkTime = 0.0f;

		if(m_blink && m_active)
		{
			dynamic_cast<sf::RectangleShape*>(m_blinker)->setSize(sf::Vector2f(m_blinkerWidth, 50.0f));
		}
		else
		{
			dynamic_cast<sf::RectangleShape*>(m_blinker)->setSize(sf::Vector2f(0.0f, 0.0f));
		}
	}
	
	sf::Vector2f blinkerPosition = 
		m_box->getPosition() + 
		sf::Vector2f(m_box->getGlobalBounds().width - (m_blinkerWidth + 2), 0.0f);

	m_blinker->setPosition(blinkerPosition);
}

void TextBox::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_box);

	target.draw(*m_text);

	target.draw(*m_blinker);

	target.draw(*m_label);
}

// Put new text into the TextBox.
void TextBox::append(sf::String text)
{
	if(m_active == true)
	{
		if(text == "\b")
		{
			truncate();
		}
		else if(text == "\r" || text == "\t")
		{
			deactivate();
		}
		else
		{
			m_text->setString(m_text->getString() + text);
		}

		resizeBox();
	}
}

// Change the caption above the TextBox.
void TextBox::setCaption(sf::String caption)
{
	m_label->setString(caption);
}

void TextBox::update(float delta)
{
	MouseManager * mm = MouseManager::instance();

	sf::Vector2i mouse = mm->getPosition();

	if(m_box->getGlobalBounds().contains(sf::Vector2f(mouse.x, mouse.y)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		activate();
	}
	
	if(!m_box->getGlobalBounds().contains(sf::Vector2f(mouse.x, mouse.y)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		deactivate();
	}

	updateBlinker(delta);
}

std::string TextBox::getString()
{
	return m_text->getString().toAnsiString(); 	
}


