#include "LeaderBoard.hpp"

#include "FontManager.hpp"

#include <SFML/Network.hpp>

#include <sstream>

#include <iostream>

LeaderBoard::LeaderBoard(float x, float y)
{
	sf::Http http("http://jacob-server.ddns.net/");

	sf::Http::Request request;

	request.setMethod(sf::Http::Request::Post);
	request.setUri("/scores.php");

	sf::Http::Response response = http.sendRequest(request);

	//std::cout << " -- " << response.getBody() << std::endl;

	std::string name;
	std::string score;

	std::istringstream ss(response.getBody());

	while(ss >> name >> score)
	{
		sf::Text * m_row = new sf::Text();

		sf::Font & font = FontManager::instance().get("mono");

		m_row->setFont(font);

		m_row->setString(name + " " + score);

		m_row->setPosition(x, y);

		y += 50.0f;

		m_rows.push_back(m_row);
	}
}

LeaderBoard::~LeaderBoard()
{

}

void LeaderBoard::scroll(float delta)
{
	for(sf::Text * text : m_rows)
	{
		text->move(sf::Vector2f(0.0f, delta) * -10.0f);
	}
}

void LeaderBoard::update(float delta)
{
	
}

void LeaderBoard::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for(sf::Text * text : m_rows)
	{
		target.draw(*text);
	}
}
