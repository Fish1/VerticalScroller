#ifndef MOUSEMANAGER_HPP
#define MOUSEMANAGER_HPP

#include <SFML/Graphics.hpp>

class MouseManager
{

private:

	MouseManager();

	~MouseManager();

	static MouseManager * s_instance;

	sf::Window * m_window = nullptr;

public:

	static MouseManager * instance();

	void setWindow(sf::Window * window);

	/*
	 * Returns position of mouse in the window
	 */

	sf::Vector2i getPosition();
};

#endif
