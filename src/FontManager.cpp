#include "FontManager.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

#include <fstream>

FontManager * FontManager::s_instance = nullptr;

FontManager::FontManager()
{

}

FontManager::~FontManager()
{
	for(auto & font : m_fonts)
	{
		delete font.second;
	}

	std::cout << "Font Manager Deleted" << std::endl;
}

FontManager & FontManager::instance()
{
	if(s_instance == nullptr)
	{
		s_instance = new FontManager();
	}

	return *s_instance;
}

void FontManager::loadFromIndex(std::string filename)
{
	std::ifstream in(filename);

	std::string fontPath = "res/fonts/";

	std::string fontFilename;

	while(in >> fontFilename)
	{
		unsigned int dotIndex = fontFilename.find(".");

		std::string key = fontFilename.substr(0, dotIndex);

		fontFilename = fontPath + fontFilename;

		loadFromFile(key, fontFilename);
	}
}

void FontManager::loadFromFile(std::string key, std::string filename)
{
	sf::Font * font = new sf::Font();

	if(!font->loadFromFile(filename))
	{
		std::cout << " -- Error -- " + filename << std::endl;

		delete font;

		return;
	}
	else
	{
		std::cout << " -- " + filename << std::endl;
	}

	m_fonts.insert(std::pair<std::string, sf::Font*>(key, font));
}

sf::Font & FontManager::get(std::string key)
{
	return *m_fonts.at(key);
}

void FontManager::cleanUp()
{
	delete s_instance;
}
