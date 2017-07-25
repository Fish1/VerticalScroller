#include "UIElement.hpp"

void UIElement::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if(m_shape != nullptr)
	{
		target.draw(*m_shape);
	}

	if(m_text != nullptr)
	{
		target.draw(*m_text);
	}
}
