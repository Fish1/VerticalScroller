#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics.hpp>

#include <string>

class LevelDisplay : public sf::Drawable
{
private:

	sf::Text * m_text;

	sf::Font * m_font;

private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	LevelDisplay(std::string text);

	~LevelDisplay();

	void update(float delta);
};

#endif
