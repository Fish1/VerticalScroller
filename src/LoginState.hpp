#ifndef LOGINSTATE_HPP
#define LOGINSTATE_HPP

#include "State.hpp"

class UIElement;

class LoginState : public State
{
private:

	UIElement * m_usernameText;

	UIElement * m_passwordText;

	UIElement * m_backButton;

	UIElement * m_loginButton;
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	void login(std::string username, std::string password);

public:

	LoginState();

	~LoginState();

	void updateInput(sf::String text);

	void update(float delta);
};

#endif
