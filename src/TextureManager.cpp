#include "TextureManager.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

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

void TextureManager::loadFromFile(std::string key, std::string filename)
{
	sf::Texture * texture = new sf::Texture();

	if(!texture->loadFromFile(filename))
	{
		std::cout << "Error Loading Texture - " + filename << std::endl;

		delete texture;

		return;
	}
	else
	{
		std::cout << "Loaded Texture - " + filename << std::endl;
	}

	m_textures.insert(std::pair<std::string, sf::Texture*>(key, texture));
}

sf::Texture & TextureManager::get(std::string key)
{
	return *m_textures.at(key);
}
