#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable
{
private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

protected:

	sf::Sprite * m_sprite = nullptr;

public:

	GameObject();

	~GameObject();

	virtual void update(float delta);

	void move(sf::Vector2f move);
	
	void setPosition(sf::Vector2f position);

	sf::Vector2f getPosition() const;

	void setRotation(float rotation);

	float getRotation() const;

	sf::FloatRect getGlobalBounds() const;
};

#endif
