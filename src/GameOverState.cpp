#include "GameOverState.hpp"

#include "GameState.hpp"

#include "MenuState.hpp"

#include "Button.hpp"

#include "Define.hpp"

#include <SFML/Network.hpp>

#include <iostream>

GameOverState::GameOverState(unsigned int score)
{
	std::cout << "Game Over State" << std::endl;

	m_menuButton = new Button(sf::Vector2f(720.0f / 2.0f, 720.0f / 1.2f), "MENU");

	m_retryButton = new Button(sf::Vector2f(720.0f / 2.0f, 720.0f / 1.5f), "RETRY");

	m_score = new Button(sf::Vector2f(720.0f / 2.0f, 200.0f), "Score: " + std::to_string(score));

	if(g_user != nullptr && g_pass != nullptr)
	{
		dynamic_cast<Button*>(m_score)->setText("Score: " + std::to_string(score) + " (Uploaded)");
	}

	if(g_user != nullptr && g_pass != nullptr)
	{
		std::string username(g_user);
		std::string password(g_pass);
		std::string scoreString = std::to_string(score);

		sf::Http http("http://jacob-server.ddns.net/");

		sf::Http::Request request;

		request.setMethod(sf::Http::Request::Post);
		request.setUri("/upload_score.php");
		request.setBody("username=" + username + "&password=" + password + "&score=" + scoreString);

		sf::Http::Response response = http.sendRequest(request);
		std::cout << " -- network status -- " << response.getStatus() << std::endl;
		std::cout << " -- " << response.getBody() << std::endl;
	}
}

GameOverState::~GameOverState()
{
	delete m_retryButton;

	delete m_menuButton;

	delete m_score;
}

void GameOverState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_retryButton);

	target.draw(*m_menuButton);

	target.draw(*m_score);
}

void GameOverState::update(float delta)
{
	m_retryButton->update(delta);

	if(dynamic_cast<Button*>(m_retryButton)->justClicked())
	{
		m_nextState = new GameState();
	}

	if(dynamic_cast<Button*>(m_menuButton)->justClicked())
	{
		m_nextState = new MenuState();
	}
}
