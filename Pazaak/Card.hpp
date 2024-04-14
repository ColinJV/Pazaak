#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using sf::Color;
using sf::RectangleShape;
using sf::Vector2f;
using sf::RenderWindow;
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

	// MUTATOR
	void setValue(int& newValue);
	void setColor(Color& newColor);

	// DISPLAY
	// This will draw the Card with an overridden function in the inherited class
	// I understand this is dumb and completely unnecessary, but it was the
	// only way I could think of to implement polymorphism into the game
	virtual void displayCard(RenderWindow& window) = 0;

protected:
	int mValue;
	RectangleShape mCard;
};

