#include "StarField.hpp"

#include "TextureManager.hpp"

#include "Star.hpp"

StarField::StarField()
{

}

void StarField::update(float delta)
{
	updateCreation(delta);

	updateMovement(delta);
}

void StarField::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for(Star * star : m_stars)
	{
		target.draw(*star);
	}
}

void StarField::updateCreation(float delta)
{
	m_lastCreation += delta;

	int random = rand() % 300;

	if(random <= m_lastCreation)
	{
		Star * star = new Star();

		star->setPosition(sf::Vector2f(rand() % 720, -10.0f));

		m_stars.push_back(star);

		m_lastCreation = 0.0f;
	}
}

void StarField::updateMovement(float delta)
{
	for(size_t index = 0; index < m_stars.size(); ++index)
	{
		Star * star = m_stars.at(index);

		star->update(delta);

		if(star->getPosition().y > 720.0f)
		{
			delete star;

			m_stars.erase(m_stars.begin() + index);

			--index;
		}
	}
}
