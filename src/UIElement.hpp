#ifndef UIELEMENT_HPP
#define UIELEMENT_HPP

#include <SFML/Graphics.hpp>

class UIElement : public sf::Drawable
{
private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

protected:

	sf::Font * m_font = nullptr;

	sf::Text * m_text = nullptr;

	sf::Shape * m_shape = nullptr;

public:

	virtual void update(float delta) = 0;

};

#endif
