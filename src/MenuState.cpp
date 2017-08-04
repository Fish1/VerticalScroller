#include "MenuState.hpp"

#include "GameState.hpp"

#include "RegisterState.hpp"

#include "LoginState.hpp"

#include "Define.hpp"

#include "Button.hpp"

#include <iostream>

#include <locale>

MenuState::MenuState()
{
	std::cout << "Menu State" << std::endl;

	m_startButton = new Button(sf::Vector2f(720.0f / 2.0f, 720.0f / 2.0f), "START");

	if(g_user == nullptr)
	{
		m_registerButton = new Button(sf::Vector2f(720.0f / 2.0f, 720.0f / 1.2f), "REGISTER");

		m_loginButton = new Button(sf::Vector2f(720.0f / 2.0f, 720.0f / 1.5f), "LOGIN");
	}
	else
	{
		std::string user(g_user);

		std::string userUpper;

		for(unsigned int index = 0; index < user.length(); ++index)
		{
			userUpper.push_back(std::toupper(user.at(index)));
		}

		m_logoutButton = new Button(sf::Vector2f(720.0f / 2.0f, 720.0f / 1.2f), "LOGOUT " + userUpper);
	}
}

MenuState::~MenuState()
{
	delete m_startButton;

	if(m_registerButton != nullptr)
	{
		delete m_registerButton;
	}

	if(m_loginButton != nullptr)
	{
		delete m_loginButton;
	}

	if(m_logoutButton != nullptr)
	{
		delete m_logoutButton;
	}
}

void MenuState::updateInput(sf::String text)
{

}

void MenuState::update(float delta)
{
	if(m_registerButton != nullptr)
	{
		m_registerButton->update(delta);

		if(dynamic_cast<Button*>(m_registerButton)->justClicked())
		{
			m_nextState = new RegisterState();
		}
	}
	
	if(m_loginButton != nullptr)
	{
		m_loginButton->update(delta);

		if(dynamic_cast<Button*>(m_loginButton)->justClicked())
		{
			m_nextState = new LoginState();
		}
	}

	if(m_logoutButton != nullptr)
	{
		m_logoutButton->update(delta);

		if(dynamic_cast<Button*>(m_logoutButton)->justClicked())
		{
			std::cout << " -- goodbye " << g_user << std::endl;

			delete g_user;

			g_user = nullptr;

			delete g_pass;

			g_pass = nullptr;

			m_nextState = new MenuState();
		}
	}

	m_startButton->update(delta);

	if(dynamic_cast<Button*>(m_startButton)->justClicked())
	{
		m_nextState = new GameState();	
	}

}

void MenuState::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*m_startButton);

	if(m_registerButton != nullptr)
	{
		target.draw(*m_registerButton);
	}

	if(m_loginButton != nullptr)
	{
		target.draw(*m_loginButton);
	}

	if(m_logoutButton != nullptr)
	{
		target.draw(*m_logoutButton);
	}
}
