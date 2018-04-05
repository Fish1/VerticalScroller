#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

//#include "Collision.hpp"

#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>

class Collision;

class GameObject : public sf::Drawable
{
private:
	
	sf::Sprite * m_sprite = nullptr;

	Collision * m_collision = nullptr;

	bool m_delete = false;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

protected:

	void setTexture(sf::Texture & texture);

	void enableCollision();
	
	void updateCollision();

public:

	GameObject();

	~GameObject();

	virtual void update(float delta);

	void setDebugColor(sf::Color color);

	void markDelete();

	bool getDelete();

	void move(sf::Vector2f move);
	
	void setPosition(sf::Vector2f position);

	sf::Vector2f getPosition() const;

	void rotate(float rotation);

	void setRotation(float rotation);

	float getRotation() const;

	sf::FloatRect getGlobalBounds() const;

	sf::FloatRect getLocalBounds() const;

	bool intersects(GameObject & other) const;
};

#endif
