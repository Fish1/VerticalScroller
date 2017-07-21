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

}

TextureManager & TextureManager::instance()
{
	if(s_instance == nullptr)
	{
		s_instance = new TextureManager;
	}

	return * s_instance;	
}

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

void TextureManager::loadFromFile(std::string key, std::string filename)
{
	sf::Texture * texture = new sf::Texture();

	if(!texture->loadFromFile(filename))
	{
		std::cout << "Error -- " + filename << std::endl;

		delete texture;

		return;
	}
	else
	{
		std::cout << " -- " + filename << std::endl;
	}

	m_textures.insert(std::pair<std::string, sf::Texture*>(key, texture));
}

sf::Texture & TextureManager::get(std::string key)
{
	return *m_textures.at(key);
}
