#pragma once
#include <iostream>
#include "Card.hpp"

using std::cout;
using std::endl;

class MainCard : public Card {
public:
	// CONSTRUCTOR
	MainCard(const int& newValue = 0) : Card(newValue) {
		mCard.setFillColor(Color::Green);
	}

	// DESTRUCTOR
	~MainCard();

	// METHODS
	void drawCardInWindow(RenderWindow& window) override;
};

