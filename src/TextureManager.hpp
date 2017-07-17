#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <map>

#include <string>

namespace sf
{
	class Texture;
}

class TextureManager
{
private:

	TextureManager();

	~TextureManager();

	static TextureManager * s_instance;

	std::map<std::string, sf::Texture *> m_textures;

public:

	static TextureManager & instance();

	void loadFromFile(std::string key, std::string filename);

	sf::Texture & get(std::string key);
};

#endif
