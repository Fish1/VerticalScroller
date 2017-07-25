#ifndef COLLISION_HPP 
#define COLLISION_HPP 

#include <SFML/Graphics.hpp>

#include <vector>

class GameObject;

class Collision : public sf::Drawable
{
private:

	sf::Vector2f m_a;
	sf::Vector2f m_b;
	sf::Vector2f m_c;
	sf::Vector2f m_d;

	std::vector<sf::Vector2f> m_debugs;

	sf::Shape * m_shape;

	GameObject * m_gameObject;

	void calculatePoints();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	bool intersectsAxis(sf::Vector2f axis, Collision & other);

public:

	Collision(GameObject * gameObject);

	~Collision();

	void setCornerColor(sf::Color color);

	void update();

	bool intersects(Collision & other);
};

#endif
