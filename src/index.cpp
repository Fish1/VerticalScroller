#include <SFML/Graphics.hpp>

#include "StateManager.hpp"

#include "TextureManager.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(720, 720), "Game of Life", sf::Style::Close);
	
	TextureManager & textureManager = TextureManager::instance();

	textureManager.loadFromFile("player", "res/ship.png");

	textureManager.loadFromFile("blueProjectile", "res/blueprojectile.png");

	textureManager.loadFromFile("enemy1", "res/enemy1.png");

	StateManager stateManager;

	while(window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		stateManager.update(window);

		window.display();
	}
}
