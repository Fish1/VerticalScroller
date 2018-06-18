#include "Star.hpp"

#include "TextureManager.hpp"

Star::Star()
{
	setAnimation(TextureManager::instance().get("star"), 2, 1, 16, 16);

	setAnimationDuration(0.01f * (rand() % 100));

	setScale(sf::Vector2f(0.3f, 0.3f));

	createColor();
}

void Star::createColor()
{
	int colorChance = rand() % 100;

	sf::Color color = sf::Color::White;

	// 16% of stars are colored
	if(colorChance < 16)
	{
		color = sf::Color(rand(), rand(), rand());
	}

	// set alpha to 200 
	color.a -= 55;
	
	// randomly remove another chunk of the alpha channel
	color.a -= (rand() % 200);

	setColor(color);
}

void Star::update(float delta)
{
	updateAnimation(delta);

	move(sf::Vector2f(0.0f, 450.0f * delta));
}
