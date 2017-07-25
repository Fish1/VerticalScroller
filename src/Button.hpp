#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "UIElement.hpp"

#include <string>

class Button : public UIElement
{
private:

public:

	Button(std::string text, sf::Vector2f position);

	virtual void update(float delta);

	bool justClicked();
};

#endif
