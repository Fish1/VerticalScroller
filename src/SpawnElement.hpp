#ifndef SPAWNELEMENT_HPP
#define SPAWNELEMENT_HPP

#include <string>

class Path;

class SpawnElement
{
private:

	const float m_delta;

	const std::string m_type;

	Path * const m_path;

public:

	SpawnElement(float delta, std::string type, Path * path);

	float getDelta();

	std::string getType();

	Path * getPath();
};

#endif
