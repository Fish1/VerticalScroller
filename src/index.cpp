#include <SFML/Graphics.hpp>

#include <iostream>

#include "StateManager.hpp"

#include "MouseManager.hpp"

#include "TextureManager.hpp"

#include "SoundBufferManager.hpp"

#include "Define.hpp"

#include <SFML/Network.hpp>

int main(void)
{
	/*
	sf::Http http("http://jacob-server.ddns.net/");

	sf::Http::Request request;

	request.setMethod(sf::Http::Request::Post);
	request.setUri("/upload_score.php");
	request.setBody("a=77&b=22");

	sf::Http::Response response = http.sendRequest(request);
	std::cout << "Network Status: " << response.getStatus() << std::endl;
	std::cout << " -- " << response.getBody() << std::endl;
	*/

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

			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::E)
				{
					g_debug = !g_debug;
				}
			}

			if(event.type == sf::Event::TextEntered)
			{
				stateManager->updateInput(event.text.unicode);
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
