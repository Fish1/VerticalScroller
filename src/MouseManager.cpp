#include "MouseManager.hpp"

MouseManager * MouseManager::s_instance = nullptr;

MouseManager::MouseManager()
{

}

MouseManager * MouseManager::instance()
{
	if(s_instance == nullptr)
	{
		s_instance = new MouseManager();
	}

	return s_instance;
}

void MouseManager::setWindow(sf::Window * window)
{
	m_window = window;
}

sf::Vector2i MouseManager::getPosition()
{
	return sf::Mouse::getPosition(*m_window);
}
