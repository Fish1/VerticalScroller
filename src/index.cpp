#include <SFML/Graphics.hpp>

#include <iostream>

#include "StateManager.hpp"

#include "TextureManager.hpp"

void loadTextures();

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(720, 720), "Game of Life", sf::Style::Close);
	
	loadTextures();

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

void loadTextures()
{
	std::cout << std::endl;

	std::cout << "Loading textures..." << std::endl;

	TextureManager & textureManager = TextureManager::instance();

	textureManager.loadFromFile("player", "res/ship.png");

	textureManager.loadFromFile("blueProjectile", "res/blueprojectile.png");
	
	textureManager.loadFromFile("redProjectile", "res/redprojectile.png");

	textureManager.loadFromFile("enemy1", "res/enemy1.png");
	
	std::cout << std::endl;
}
