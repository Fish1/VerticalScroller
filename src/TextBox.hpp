#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>

#include "UIElement.hpp"

class TextBox : public UIElement
{
private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	bool m_active = false;

	bool m_blink = true;

	float m_blinkerWidth = 25.0f;

	float m_blinkTime = 0.0f;

	sf::Shape * m_blinker = nullptr;

	sf::Text * m_label = nullptr;

	void truncate();

	void resizeBox();

	void activate();

	void deactivate();

	void updateBlinker(float delta);

public:

	TextBox(sf::Vector2f position, std::string label);

	~TextBox();

	std::string getString();

	void append(sf::String text);

	void setCaption(sf::String caption);

	virtual void update(float delta);

};

#endif
