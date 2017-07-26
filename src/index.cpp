#include <SFML/Graphics.hpp>

#include <iostream>

#include "StateManager.hpp"

#include "MouseManager.hpp"

#include "TextureManager.hpp"

#include "SoundBufferManager.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(720, 720), "Agalag", sf::Style::Close);

	std::cout << std::endl;

	std::cout << "Loading Textures..." << std::endl;

	TextureManager::instance().loadFromIndex("res/textures/textureIndex.txt");
	
	std::cout << std::endl;

	std::cout << "Loading Sounds..." << std::endl;

	SoundBufferManager::instance().loadFromFile("galaga_shoot1", "res/sound/galaga_shoot1.ogg");

	std::cout << std::endl;

	StateManager * stateManager = new StateManager();

	MouseManager::instance()->setWindow(&window);

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

		stateManager->update(window);
		
		window.display();
	}

	std::cout << std::endl;

	std::cout << "Good-Bye!" << std::endl;

	TextureManager::instance().cleanUp();

	SoundBufferManager::instance().cleanUp();
}
