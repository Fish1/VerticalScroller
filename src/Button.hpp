#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "UIElement.hpp"

#include <string>

class Button : public UIElement
{
private:

	bool m_lmbClicked = false;

	void updateSize();

public:

	Button(sf::Vector2f position, std::string text);

	virtual void update(float delta);

	bool justClicked();

	void setText(std::string text);
};

#endif
