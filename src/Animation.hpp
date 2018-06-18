#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>

#include <SFML/Graphics.hpp>

class Animation
{
private:

	std::vector<sf::Texture> m_textures;

	unsigned int m_textureCount;

	float m_totalDuration;

	float m_currentDuration;

	unsigned int m_currentTexture;

public:

	Animation(sf::Texture & texture, unsigned int sheetWidth, unsigned int sheetHeight, unsigned int width, unsigned int height);

	void setDuration(float duration);

	void update(float delta);

	sf::Texture & getTexture();

};

#endif
