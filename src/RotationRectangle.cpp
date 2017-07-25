#include "RotationRectangle.hpp"

#include "GameObject.hpp"

#include "Define.hpp"

#include "Math.hpp"

#include <vector>

#include <iostream>

RotationRectangle::RotationRectangle(GameObject * gameObject)
{
	m_gameObject = gameObject;

	m_shape = new sf::CircleShape(3.0f);

	m_shape->setOrigin(m_shape->getLocalBounds().width / 2.0f, m_shape->getLocalBounds().height / 2.0f);

	m_shape->setFillColor(sf::Color::Green);
}

RotationRectangle::~RotationRectangle()
{
	delete m_shape;
}

void RotationRectangle::calculatePoints()
{
	sf::FloatRect bounds = m_gameObject->getLocalBounds();

	float radius = sqrt(bounds.height * bounds.height + bounds.width * bounds.width);

	float rotation = m_gameObject->getRotation() * PI / 180.0f;

	float theta = atan2(bounds.height / 2.0f, bounds.width / 2.0f) + rotation;
	float x = cos(theta);
	float y = sin(theta);
	m_a = m_gameObject->getPosition() + sf::Vector2f(x, y) * radius;
	
	theta = atan2(bounds.height / 2.0f, -bounds.width / 2.0f) + rotation;
	x = cos(theta);
	y = sin(theta);
	m_b = m_gameObject->getPosition() + sf::Vector2f(x, y) * radius;
	
	theta = atan2(-bounds.height / 2.0f, -bounds.width / 2.0f) + rotation;
	x = cos(theta);
	y = sin(theta);
	m_c = m_gameObject->getPosition() + sf::Vector2f(x, y) * radius;
	
	theta = atan2(-bounds.height / 2.0f, bounds.width / 2.0f) + rotation;
	x = cos(theta);
	y = sin(theta);
	m_d = m_gameObject->getPosition() + sf::Vector2f(x, y) * radius;
};

void RotationRectangle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	m_shape->setPosition(m_a);
	target.draw(*m_shape);

	m_shape->setPosition(m_b);
	target.draw(*m_shape);

	m_shape->setPosition(m_c);
	target.draw(*m_shape);

	m_shape->setPosition(m_d);
	target.draw(*m_shape);

	for(sf::Vector2f p : m_debugs)
	{
		m_shape->setPosition(p);
		target.draw(*m_shape);
	}
}

void RotationRectangle::setCornerColor(sf::Color color)
{
	m_shape->setFillColor(color);
}

void RotationRectangle::update(float delta)
{
	m_debugs.clear();

	calculatePoints();
}

bool RotationRectangle::intersectsAxis(sf::Vector2f axis, RotationRectangle & other)
{
	sf::Vector2f other_a = Math::projectPoint(other.m_a, axis);
	sf::Vector2f other_b = Math::projectPoint(other.m_b, axis);
	sf::Vector2f other_c = Math::projectPoint(other.m_c, axis);
	sf::Vector2f other_d = Math::projectPoint(other.m_d, axis);

	sf::Vector2f this_a = Math::projectPoint(m_a, axis);
	sf::Vector2f this_b = Math::projectPoint(m_b, axis);
	sf::Vector2f this_c = Math::projectPoint(m_c, axis);
	sf::Vector2f this_d = Math::projectPoint(m_d, axis);

	m_debugs.push_back(other_a);
	m_debugs.push_back(other_b);
	m_debugs.push_back(other_c);
	m_debugs.push_back(other_d);
	
	m_debugs.push_back(this_a);
	m_debugs.push_back(this_b);
	m_debugs.push_back(this_c);
	m_debugs.push_back(this_d);

	std::vector<float> otherX;

	otherX.push_back(other_a.x);
	otherX.push_back(other_b.x);
	otherX.push_back(other_c.x);
	otherX.push_back(other_d.x);

	std::sort(otherX.begin(), otherX.end());

	std::vector<float> thisX;

	thisX.push_back(this_a.x);
	thisX.push_back(this_b.x);
	thisX.push_back(this_c.x);
	thisX.push_back(this_d.x);

	std::sort(thisX.begin(), thisX.end());

	bool intersectX = false;

	/*
	std::cout << "EnemyX: " << *thisX.begin() << " - " << *(thisX.end() - 1) << std::endl;
	std::cout << "PlayerX: " << *otherX.begin() << " - " << *(otherX.end() - 1) << std::endl;
	*/

	if(*thisX.begin() <= *(otherX.end() - 1) && *thisX.begin() >= *otherX.begin())
	{
		intersectX = true;
	}
	else if(*(thisX.end() - 1) <= *(otherX.end() - 1) && *(thisX.end() - 1) >= *otherX.begin())
	{
		intersectX = true;
	}
	else if(*(thisX.end() - 1) >= *(otherX.end() - 1) && *thisX.begin() <= *otherX.begin())
	{
		intersectX = true;
	}
	
	std::vector<float> otherY;

	otherY.push_back(other_a.y);
	otherY.push_back(other_b.y);
	otherY.push_back(other_c.y);
	otherY.push_back(other_d.y);

	std::sort(otherY.begin(), otherY.end());

	std::vector<float> thisY;

	thisY.push_back(this_a.y);
	thisY.push_back(this_b.y);
	thisY.push_back(this_c.y);
	thisY.push_back(this_d.y);

	std::sort(thisY.begin(), thisY.end());

	bool intersectY = false;
	
	/*
	std::cout << "EnemyY: " << *thisY.begin() << " - " << *(thisY.end() - 1) << std::endl;
	std::cout << "PlayerY: " << *otherY.begin() << " - " << *(otherY.end() - 1) << std::endl;
	*/

	if(*thisY.begin() <= *(otherY.end() - 1) && *thisY.begin() >= *otherY.begin())
	{
		intersectY = true;
	}
	else if(*(thisY.end() - 1) <= *(otherY.end() - 1) && *(thisY.end() - 1) >= *otherY.begin())
	{
		intersectY = true;
	}
	else if(*(thisY.end() - 1) >= *(otherY.end() - 1) && *thisY.begin() <= *otherY.begin())
	{
		intersectY = true;
	}
	
	return intersectY && intersectX;
}

bool RotationRectangle::intersects(RotationRectangle & other)
{
	// project to yaxis of this
	
	sf::Vector2f axis_a = m_a - m_b;

	// project to xaxis of this

	sf::Vector2f axis_b = m_b - m_c;

	// project to yaxis of other
	
	sf::Vector2f axis_c = other.m_a - other.m_b;
	
	// project to xaxis of other

	sf::Vector2f axis_d = other.m_b - other.m_c;

	bool a = intersectsAxis(axis_a, other);
	bool b = intersectsAxis(axis_b, other);
	bool c = intersectsAxis(axis_c, other); 
	bool d = intersectsAxis(axis_d, other);

	//std::cout << a << b << c << d << std::endl;

	return a && b && c && d;
}
