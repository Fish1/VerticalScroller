#include "LoginState.hpp"

#include "MenuState.hpp"

#include "TextBox.hpp"

#include "Button.hpp" 
#include "Define.hpp"

#include <SFML/Network.hpp>

#include <cstring>

#include <iostream>

LoginState::LoginState()
{
	std::cout << "Login State" << std::endl;

	m_usernameText = new TextBox(sf::Vector2f(50.0f, 100.0f), "Username:");
	
	m_passwordText = new TextBox(sf::Vector2f(50.0f, 300.0f), "Password:");

	m_backButton = new Button(sf::Vector2f(720.0f * (1.0f / 3.0f), 500.0f), "BACK");

	m_loginButton = new Button(sf::Vector2f(720.0f * (2.0f / 3.0f), 500.0f), "LOGIN");
}

LoginState::~LoginState()
{
	delete m_usernameText;

	delete m_passwordText;

	delete m_backButton;

	delete m_loginButton;
}

void LoginState::login(std::string username, std::string password)
{
	sf::Http http("http://jacob-enders.ddns.net/");

	sf::Http::Request request;

	request.setMethod(sf::Http::Request::Post);
	request.setUri("/login_user.php");
	request.setBody("username=" + username + "&password=" + password);

	sf::Http::Response response = http.sendRequest(request);
	std::cout << " -- network status -- " << response.getStatus() << std::endl;
	std::cout << " -- " << response.getBody() << std::endl;

	if(response.getBody() == "welcome " + username)
	{
		setCredentials(username, password);

		m_nextState = new MenuState();
	}
	else if(response.getStatus() == 1001)
	{
		dynamic_cast<TextBox*>(m_usernameText)->setCaption("Username: (No Connection)");
	}
	else
	{
		dynamic_cast<TextBox*>(m_usernameText)->setCaption("Username: (Invalid Login)");
	}
}

void LoginState::updateText(sf::String text)
{
	dynamic_cast<TextBox*>(m_usernameText)->append(text);

	dynamic_cast<TextBox*>(m_passwordText)->append(text);
}

void LoginState::update(float delta)
{
	m_usernameText->update(delta);

	m_passwordText->update(delta);

	m_backButton->update(delta);

	if(dynamic_cast<Button*>(m_backButton)->justClicked())
	{
		m_nextState = new MenuState();
	}

	m_loginButton->update(delta);

	if(dynamic_cast<Button*>(m_loginButton)->justClicked())
	{
		std::string user = dynamic_cast<TextBox*>(m_usernameText)->getString();

		std::string pass = dynamic_cast<TextBox*>(m_passwordText)->getString();

		login(user, pass);
	}
}

void LoginState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_usernameText);

	target.draw(*m_passwordText);

	target.draw(*m_backButton);

	target.draw(*m_loginButton);
}
