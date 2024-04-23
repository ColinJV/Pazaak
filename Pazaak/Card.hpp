#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using sf::Color;
using sf::RectangleShape;
using sf::Vector2f;
using sf::RenderWindow;
using sf::Text;
using sf::Font;
using std::cout;
using std::endl;

class Card
{
public:
	// CONSTRUCTOR
	Card(const int& cardValue = 0);

	// DESTRUCTOR
	virtual ~Card();

	// ACCESSOR
	const int& getValue(void) const;
	const Color& getColor(void) const;
	const RectangleShape& getShape(void) const;
	const Text& getText(void) const;

	// MUTATOR
	void setValue(int& newValue);
	void setColor(Color& newColor);
	void setPosition(const Vector2f& newPosition);

	// DISPLAY
	virtual void drawCardInWindow(RenderWindow& window) = 0;
	void drawCardBackInWindow(RenderWindow& window);

protected:
	int mValue;
	RectangleShape mCard;
	RectangleShape mCardBack;
	Text mText;
	Font fontType;
	sf::Texture cardTexture; // CB 4/21/2024
};

