#include "SpawnElement.hpp"

#include "Path.hpp"

SpawnElement::SpawnElement(float delta, std::string type, Path * path) : 
	m_delta(delta), m_type(type), m_path(path)
{

}

float SpawnElement::getDelta()
{
	return m_delta;
}

std::string SpawnElement::getType()
{
	return m_type;
}

Path * SpawnElement::getPath()
{
	return m_path;
}
