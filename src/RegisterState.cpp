#include "RegisterState.hpp"

#include "MenuState.hpp"

#include "TextBox.hpp"

#include "Button.hpp"

#include "Define.hpp"

#include <SFML/Network.hpp>

#include <iostream>

RegisterState::RegisterState()
{
	std::cout << "Register State" << std::endl;

	m_usernameText = new TextBox(sf::Vector2f(50.0f, 100.0f), "Username:");

	m_passwordText = new TextBox(sf::Vector2f(50.0f, 300.0f), "Password:");

	m_backButton = new Button(sf::Vector2f(720.0f * (1.0f / 3.0f), 500.0f), "BACK");

	m_registerButton = new Button(sf::Vector2f(720.0f * (2.0f / 3.0f), 500.0f), "REGISTER");
}

RegisterState::~RegisterState()
{
	delete m_usernameText;

	delete m_passwordText;

	delete m_backButton;

	delete m_registerButton;
}

void RegisterState::registerUser(std::string username, std::string password)
{
	if(username.size() == 0 || password.size() == 0)
	{
		std::cout << "Registering" << std::endl;
		std::cout << " -- Error: username or password invalid" << std::endl;
		
		dynamic_cast<TextBox*>(m_usernameText)->setCaption("Username: (Invalid Username)");	
	
		return;
	}

	sf::Http http("http://jacobenders.ddns.net/");

	sf::Http::Request request;

	request.setMethod(sf::Http::Request::Post);
	request.setUri("/~jacob/register_user.php");
	request.setBody("username=" + username + "&password=" + password);

	sf::Http::Response response = http.sendRequest(request);
	std::cout << " -- network status -- " << response.getStatus() << std::endl;
	std::cout << " -- " << response.getBody() << std::endl;
	
	if(response.getStatus() == 1001)
	{
		dynamic_cast<TextBox*>(m_usernameText)->setCaption("Username: (No Connection)");	

	}

	if(response.getBody() == "user already exists")
	{
		dynamic_cast<TextBox*>(m_usernameText)->setCaption("Username: (" + username + " already exists)");	
	}

	if(response.getBody() == "user registered")
	{
		setCredentials(username, password);

		m_nextState = new MenuState();
	}

}

void RegisterState::updateText(sf::String text)
{
	dynamic_cast<TextBox*>(m_usernameText)->append(text);

	dynamic_cast<TextBox*>(m_passwordText)->append(text);
}

void RegisterState::update(float delta)
{
	m_usernameText->update(delta);
	
	m_passwordText->update(delta);

	m_backButton->update(delta);

	if(dynamic_cast<Button*>(m_backButton)->justClicked())
	{
		m_nextState = new MenuState();
	}

	m_registerButton->update(delta);

	if(dynamic_cast<Button*>(m_registerButton)->justClicked())
	{
		std::string user = dynamic_cast<TextBox*>(m_usernameText)->getString();

		std::string pass = dynamic_cast<TextBox*>(m_passwordText)->getString();

		registerUser(user, pass);
	}
}

void RegisterState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_usernameText);

	target.draw(*m_passwordText);

	target.draw(*m_backButton);

	target.draw(*m_registerButton);
}
