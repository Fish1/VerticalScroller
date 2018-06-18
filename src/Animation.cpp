#include "Animation.hpp"

Animation::Animation(sf::Texture & texture, 
	unsigned int sheetWidth, unsigned int sheetHeight, 
	unsigned int width, unsigned int height)
{
	m_totalDuration = 1.0f;

	m_currentDuration = 0.0f;

	m_textureCount = sheetWidth * sheetHeight;

	m_currentTexture = 0;

	sf::Image sheet = texture.copyToImage();

	for(unsigned int y = 0; y < sheetHeight; ++y)
	{
		for(unsigned int x = 0; x < sheetWidth; ++x)
		{
			sf::Texture part;
			part.loadFromImage(sheet,
			sf::IntRect(x * width, y * width, width, height));

			m_textures.push_back(part);
		}
	}

	if(sheetWidth == 0 || sheetHeight == 0 || width == 0 || height == 0)
	{
		m_textures.clear();

		m_textures.push_back(sf::Texture(texture));

		m_textureCount = 1;
	}
}

void Animation::setDuration(float duration)
{
	m_totalDuration = duration;
}

void Animation::update(float delta)
{
	m_currentDuration += delta;

	if(m_currentDuration >= m_totalDuration)
	{
		m_currentDuration = 0.0f;

		m_currentTexture += 1;

		if(m_currentTexture == m_textureCount)
		{
			m_currentTexture = 0;
		}
	}
}

sf::Texture & Animation::getTexture()
{
	return m_textures.at(m_currentTexture);
}
