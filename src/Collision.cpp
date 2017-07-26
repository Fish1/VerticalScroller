#include "Collision.hpp"

#include "GameObject.hpp"

#include "Define.hpp"

#include "Math.hpp"

#include <vector>

#include <iostream>

Collision::Collision(GameObject & gameObject) :
	m_gameObject(gameObject)
{

}

Collision::~Collision()
{

}

void Collision::calculatePoints()
{
	sf::FloatRect bounds = m_gameObject.getLocalBounds();

	float radius = sqrt(bounds.height * bounds.height + bounds.width * bounds.width);

	float rotation = m_gameObject.getRotation() * PI / 180.0f;

	float theta = atan2(bounds.height / 2.0f, bounds.width / 2.0f) + rotation;
	float x = cos(theta);
	float y = sin(theta);
	m_a = m_gameObject.getPosition() + sf::Vector2f(x, y) * radius;
	
	theta = atan2(bounds.height / 2.0f, -bounds.width / 2.0f) + rotation;
	x = cos(theta);
	y = sin(theta);
	m_b = m_gameObject.getPosition() + sf::Vector2f(x, y) * radius;
	
	theta = atan2(-bounds.height / 2.0f, -bounds.width / 2.0f) + rotation;
	x = cos(theta);
	y = sin(theta);
	m_c = m_gameObject.getPosition() + sf::Vector2f(x, y) * radius;
	
	theta = atan2(-bounds.height / 2.0f, bounds.width / 2.0f) + rotation;
	x = cos(theta);
	y = sin(theta);
	m_d = m_gameObject.getPosition() + sf::Vector2f(x, y) * radius;
};

void Collision::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Vertex box[5];
	box[0].position = m_a;
	box[0].color = m_debugColor;
	box[1].position = m_b;
	box[1].color = m_debugColor;
	box[2].position = m_c;
	box[2].color = m_debugColor;
	box[3].position = m_d;
	box[3].color = m_debugColor;
	box[4].position = m_a;
	box[4].color = m_debugColor;
	
	target.draw(&box[0], 5, sf::LineStrip);

	for(unsigned int index_axis = 0; index_axis < m_debugs.size(); ++index_axis)
	{
		sf::Vertex axisLine[m_debugs.at(index_axis).size()];

		for(unsigned int index_point = 0; index_point < m_debugs.at(index_axis).size(); ++index_point)
		{
			axisLine[index_point].position = m_debugs.at(index_axis).at(index_point) + sf::Vector2f(1.0f, 1.0f);
			axisLine[index_point].color = m_debugColor;
		}

		target.draw(&axisLine[0], m_debugs.at(index_axis).size(), sf::LineStrip);
	}
}

void Collision::setCornerColor(sf::Color color)
{
	m_debugColor = color;
}

void Collision::update()
{
	m_debugs.clear();

	calculatePoints();
}

bool Collision::intersectsAxis(sf::Vector2f axis, Collision & other)
{
	sf::Vector2f other_a = Math::projectPoint(other.m_a, axis);
	sf::Vector2f other_b = Math::projectPoint(other.m_b, axis);
	sf::Vector2f other_c = Math::projectPoint(other.m_c, axis);
	sf::Vector2f other_d = Math::projectPoint(other.m_d, axis);

	sf::Vector2f this_a = Math::projectPoint(m_a, axis);
	sf::Vector2f this_b = Math::projectPoint(m_b, axis);
	sf::Vector2f this_c = Math::projectPoint(m_c, axis);
	sf::Vector2f this_d = Math::projectPoint(m_d, axis);

	std::vector<sf::Vector2f> otherDebugs;
	otherDebugs.push_back(other_a);
	otherDebugs.push_back(other_b);
	otherDebugs.push_back(other_c);
	otherDebugs.push_back(other_d);
	
	other.m_debugs.push_back(otherDebugs);

	std::vector<sf::Vector2f> thisDebugs;
	thisDebugs.push_back(this_a);
	thisDebugs.push_back(this_b);
	thisDebugs.push_back(this_c);
	thisDebugs.push_back(this_d);

	m_debugs.push_back(thisDebugs);

	std::vector<float> otherX;

	otherX.push_back(other_a.x);
	otherX.push_back(other_b.x);
	otherX.push_back(other_c.x);
	otherX.push_back(other_d.x);

	float otherMaxX = *std::max_element(otherX.begin(), otherX.end());
	float otherMinX = *std::min_element(otherX.begin(), otherX.end());

	std::vector<float> thisX;

	thisX.push_back(this_a.x);
	thisX.push_back(this_b.x);
	thisX.push_back(this_c.x);
	thisX.push_back(this_d.x);

	float thisMaxX = *std::max_element(thisX.begin(), thisX.end());
	float thisMinX = *std::min_element(thisX.begin(), thisX.end());

	bool intersectX = true;

	if(thisMinX > otherMaxX || thisMaxX < otherMinX)
	{
		intersectX = false;
	}

	if(intersectX == false)
	{
		return false;
	}
	
	std::vector<float> otherY;

	otherY.push_back(other_a.y);
	otherY.push_back(other_b.y);
	otherY.push_back(other_c.y);
	otherY.push_back(other_d.y);

	float otherMaxY = *std::max_element(otherY.begin(), otherY.end());
	float otherMinY = *std::min_element(otherY.begin(), otherY.end());

	std::vector<float> thisY;

	thisY.push_back(this_a.y);
	thisY.push_back(this_b.y);
	thisY.push_back(this_c.y);
	thisY.push_back(this_d.y);

	float thisMaxY = *std::max_element(thisY.begin(), thisY.end());
	float thisMinY = *std::min_element(thisY.begin(), thisY.end());

	bool intersectY = true;
	
	if(thisMinY > otherMaxY || thisMaxY < otherMinY)
	{
		intersectY = false;
	}

	return intersectY && intersectX;
}

bool Collision::intersects(Collision & other)
{
	// project to yaxis of this
	
	sf::Vector2f axis_a = m_a - m_b;

	// project to xaxis of this

	sf::Vector2f axis_b = m_b - m_c;

	// project to yaxis of other
	
	sf::Vector2f axis_c = other.m_a - other.m_b;
	
	// project to xaxis of other

	sf::Vector2f axis_d = other.m_b - other.m_c;

	return intersectsAxis(axis_a, other) &&
		intersectsAxis(axis_b, other) &&
		intersectsAxis(axis_c, other) &&
		intersectsAxis(axis_d, other);
}
