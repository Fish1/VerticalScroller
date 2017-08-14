#include "TextureManager.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

#include <fstream>

TextureManager * TextureManager::s_instance = nullptr;

TextureManager::TextureManager()
{
	
}

TextureManager::~TextureManager()
{
	for(auto & texture : m_textures)
	{
		delete texture.second;
	}

	std::cout << "Texture Manager Deleted" << std::endl;
}

// Provide global access to a single TextureManager instance.
TextureManager & TextureManager::instance()
{
	if(s_instance == nullptr)
	{
		s_instance = new TextureManager;
	}

	return * s_instance;	
}

// Load a list of textures from an index file. The keys will be the
// filename minus the extention.
void TextureManager::loadFromIndex(std::string filename)
{
	std::ifstream in(filename);

	std::string texturePath = "res/textures/";

	std::string textureFilename;

	while(in >> textureFilename)
	{
		unsigned int dotIndex = textureFilename.find(".");
		
		std::string key = textureFilename.substr(0, dotIndex);

		textureFilename = texturePath + textureFilename;

		loadFromFile(key, textureFilename);
	}
}

// Load a single texture and give it a key to be referenced by.
void TextureManager::loadFromFile(std::string key, std::string filename)
{
	sf::Texture * texture = new sf::Texture();

	if(!texture->loadFromFile(filename))
	{
		std::cout << " -- Error -- " + filename << std::endl;

		delete texture;

		return;
	}
	else
	{
		std::cout << " -- " + filename << std::endl;
	}

	m_textures.insert(std::pair<std::string, sf::Texture*>(key, texture));
}

// Return they texture that is associdated with a given key.
sf::Texture & TextureManager::get(std::string key)
{
	return *m_textures.at(key);
}

// Loop through all the loaded textures and free the memory.
void TextureManager::cleanUp()
{
	delete s_instance;
}
