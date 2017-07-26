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

	/*
	 * Loads a list of textures from an index file
	 * The keys will be the filename minus the extention
	 */

	void loadFromIndex(std::string filename);

	/*
	 * Loads a single texture given a custom key
	 */

	void loadFromFile(std::string key, std::string filename);

	/*
	 * Returns the texture that is associated with the
	 * key that is given as an argument
	 */

	sf::Texture & get(std::string key);

	void cleanUp();
};

#endif
