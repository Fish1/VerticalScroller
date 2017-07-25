#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "RotationRectangle.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameObject : public sf::Drawable
{
private:
	
	sf::Sprite * m_sprite = nullptr;

	RotationRectangle * m_rectangle = nullptr;

	bool m_delete = false;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

protected:

	void setTexture(sf::Texture & texture);

	void enableRotationRectangle();

public:

	GameObject();

	~GameObject();

	virtual void update(float delta);

	void setDebugColor(sf::Color color);

	void updateRotationRectangle();

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
