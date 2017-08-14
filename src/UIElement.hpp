#ifndef UIELEMENT_HPP
#define UIELEMENT_HPP

#include <SFML/Graphics.hpp>

class UIElement : public sf::Drawable
{
private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const = 0;

public:

	virtual void update(float delta) = 0;

};

#endif
