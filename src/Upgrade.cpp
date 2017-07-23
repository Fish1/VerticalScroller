#include "Upgrade.hpp"

void Upgrade::update(float delta)
{
	move(sf::Vector2f(0.0f, 125.0f) * delta);
}
