#ifndef REGISTERSTATE_HPP
#define REGISTERSTATE_HPP

#include "State.hpp"

class UIElement;

class RegisterState : public State
{
private:

	UIElement * m_usernameText;

	UIElement * m_passwordText;

	UIElement * m_backButton;

	UIElement * m_registerButton;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	void registerUser(std::string username, std::string password);

public:

	RegisterState();

	~RegisterState();

	void updateText(sf::String text);

	void update(float delta);
};

#endif
