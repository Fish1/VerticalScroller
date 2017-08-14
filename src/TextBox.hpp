#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>

#include "UIElement.hpp"

class TextBox : public UIElement
{
private:

	bool m_active = false;

	bool m_blink = true;

	float m_blinkerWidth = 25.0f;

	float m_blinkTime = 0.0f;

	sf::Shape * m_box = nullptr;

	sf::Text * m_text = nullptr;

	sf::Shape * m_blinker = nullptr;

	sf::Text * m_label = nullptr;

	/*
	 *	Remove the last character that was inserted into
	 *	the TextBox.
	 *
	 *	@param - none
	 *
	 *	@return - void
	 */
	void truncate();

	/*
	 *	Reshape the TextBox as the user types into it.
	 *
	 *	@param - none
	 *
	 *	@return - void
	 */
	void resizeBox();

	/*
	 *	Set the state of the TextBox so that when
	 *	the user types, the text is inserted into
	 *	this TextBox.
	 *
	 *	@param - none
	 *
	 *	@return - void
	 */
	void activate();

	/*
	 *	Set the state of the TextBox so that when
	 *	the user types, the text is not inserted
	 *	into this TextBox.
	 *
	 *	@param - none
	 *
	 *	@return - void
	 */
	void deactivate();

	/*
	 *	When the TextBox is active, the blinker
	 *	will blink and indicate that this TextBox
	 *	is active.
	 *
	 *	@param1 - Time step to control blink rate.
	 *
	 *	@return - void
	 */
	void updateBlinker(float delta);
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

public:

	TextBox(sf::Vector2f position, std::string label);

	~TextBox();

	/*
	 *	Put new text into the TextBox.
	 *
	 *	@param1 - The new text.
	 *
	 *	@return - void
	 */
	void append(sf::String text);

	/*
	 *	Change the caption above the TextBox.
	 *
	 *	@param1 - The new text to be displayed.
	 *
	 *	@return - void
	 */
	void setCaption(sf::String caption);

	virtual void update(float delta);

	std::string getString();
};

#endif
