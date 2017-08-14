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

	/*
	 *	Provide global access to a single TextureManager
	 *	instance.
	 *
	 *	@param - none
	 *
	 *	@return - A reference to the global TextureManager.
	 */
	static TextureManager & instance();

	/*
	 * 	Load a list of textures from an index file.
	 * 	The keys will be the filename minus the extention.
	 *
	 * 	@param1 - The filename of the index file to load.
	 * 	@return - void
	 */
	void loadFromIndex(std::string filename);

	/*
	 *	Loads a single texture and give it a key
	 *	to be referenced by.
	 *
	 *	@param1 - The key to access the texture by.
	 *	@param2 - The filename of the texture to load.
	 *
	 *	@return - void
	 */
	void loadFromFile(std::string key, std::string filename);

	/*
	 *	Returns the texture that is associated with a
	 *	given key.
	 *
	 *	@param1 - The key to access a specific texture.
	 *	
	 *	@return - A reference to a texture.
	 */
	sf::Texture & get(std::string key);

	/*
	 *	Loop through all the loaded textures and free
	 *	the memeory.
	 *
	 *	@param - none
	 *
	 *	@return - void
	 */
	void cleanUp();
};

#endif
