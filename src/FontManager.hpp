#ifndef FONTMANAGER_HPP
#define FONTMANAGER_HPP

#include <map>

#include <string>

namespace sf
{
	class Font;
}

class FontManager
{
private:

	FontManager();

	~FontManager();

	static FontManager * s_instance;

	std::map<std::string, sf::Font *> m_fonts;

public:

	static FontManager & instance();

	void loadFromIndex(std::string filename);

	void loadFromFile(std::string key, std::string filename);

	sf::Font & get(std::string key);

	void cleanUp();
};

#endif
