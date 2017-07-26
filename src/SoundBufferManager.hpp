#ifndef SOUNDBUFFERMANAGER_HPP
#define SOUNDBUFFERMANAGER_HPP

#include <map>

#include <string>

namespace sf
{
	class SoundBuffer;
}

class SoundBufferManager
{
private:

	SoundBufferManager();

	~SoundBufferManager();

	static SoundBufferManager * s_instance;

	std::map<std::string, sf::SoundBuffer *> m_soundBuffers;

public:

	static SoundBufferManager & instance();

	void loadFromFile(std::string key, std::string filename);

	sf::SoundBuffer & get(std::string key);

	void cleanUp();
};

#endif
