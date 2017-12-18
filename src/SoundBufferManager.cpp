#include "SoundBufferManager.hpp"

#include <SFML/Audio.hpp>

#include <iostream>

#include <fstream>

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

void SoundBufferManager::loadFromIndex(std::string filename)
{
	std::ifstream in(filename);

	std::string soundPath = "res/sounds/";

	std::string soundFilename;

	while(in >> soundFilename)
	{
		unsigned int dotIndex = soundFilename.find(".");

		std::string key = soundFilename.substr(0, dotIndex);

		soundFilename = soundPath + soundFilename;

		loadFromFile(key, soundFilename);
	}
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
