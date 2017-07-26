#include "SoundBufferManager.hpp"

#include <SFML/Audio.hpp>

#include <iostream>

SoundBufferManager * SoundBufferManager::s_instance = nullptr;

SoundBufferManager::SoundBufferManager()
{

}

SoundBufferManager::~SoundBufferManager()
{
	std::cout << "Sound Buffer Manager Deleted" << std::endl;

	for(auto & sound : m_soundBuffers)
	{
		delete sound.second;
	}
}

SoundBufferManager & SoundBufferManager::instance()
{
	if(s_instance == nullptr)
	{
		s_instance = new SoundBufferManager();
	}

	return * s_instance;
}

void SoundBufferManager::loadFromFile(std::string key, std::string filename)
{
	sf::SoundBuffer * soundBuffer = new sf::SoundBuffer();

	if(!soundBuffer->loadFromFile(filename))
	{
		std::cout << "Error -- " + filename << std::endl;

		delete soundBuffer;

		return;
	}
	else
	{
		std::cout << " -- " + filename << std::endl;
	}

	m_soundBuffers.insert(std::pair<std::string, sf::SoundBuffer*>(key, soundBuffer));
}

sf::SoundBuffer & SoundBufferManager::get(std::string key)
{
	return *m_soundBuffers.at(key);
}

void SoundBufferManager::cleanUp()
{
	delete s_instance;
}
