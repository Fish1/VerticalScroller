#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "UIElement.hpp"

#include <string>

class Button : public UIElement
{
private:

	sf::Text * m_text;

	sf::Shape * m_shape;

	bool m_lmbClicked = false;

	void updateSize();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	Button(sf::Vector2f position, std::string text);

	~Button();

	virtual void update(float delta);

	bool justClicked();

	void setText(std::string text);
};

#endif
