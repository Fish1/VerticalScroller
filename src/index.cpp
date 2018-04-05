#include <SFML/Graphics.hpp>

#include <SFML/Network.hpp>

#include <iostream>

#include "StateManager.hpp"

#include "MouseManager.hpp"

#include "TextureManager.hpp"

#include "FontManager.hpp"

#include "SoundBufferManager.hpp"

#include "Define.hpp"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(720, 720), "Agalag", sf::Style::Close);

	std::cout << std::endl;

	std::cout << "Loading Textures..." << std::endl;

	TextureManager::instance().loadFromIndex("res/textures/textureIndex.txt");
	
	std::cout << std::endl;

	std::cout << "Loading Sounds..." << std::endl;

	SoundBufferManager::instance().loadFromIndex("res/sounds/soundIndex.txt");

	std::cout << std::endl;

	std::cout << "Loading Fonts..." << std::endl;

	FontManager::instance().loadFromIndex("res/fonts/fontIndex.txt");

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

			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::E)
				{
					g_debug = !g_debug;
				}
			}

			if(event.type == sf::Event::TextEntered)
			{
				stateManager->updateText(event.text.unicode);
			}

			if(event.type == sf::Event::MouseWheelScrolled)
			{
				stateManager->updateScroll(event.mouseWheelScroll.delta);
			}
		}

		stateManager->update(window);
		
		window.display();
	}

	std::cout << std::endl;

	std::cout << "Good-Bye!" << std::endl;

	TextureManager::instance().cleanUp();

	SoundBufferManager::instance().cleanUp();

	FontManager::instance().cleanUp();

	return 0;
}
