#include "Upgrade.hpp"

void Upgrade::update(float delta)
{
	m_sprite->move(sf::Vector2f(0.0f, 125.0f) * delta);
}
