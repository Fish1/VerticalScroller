#include <SFML/Graphics.hpp>

#include <iostream>

#include "StateManager.hpp"

#include "TextureManager.hpp"

void loadTextures();

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(720, 720), "Game of Life", sf::Style::Close);

	std::cout << std::endl;

	std::cout << "Loading Textures..." << std::endl;

	TextureManager::instance().loadFromIndex("res/textures/textureIndex.txt");
	
	std::cout << std::endl;

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
