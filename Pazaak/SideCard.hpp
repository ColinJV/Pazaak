#pragma once
#include "Card.hpp"

class SideCard : public Card {
public:
	// CONSTRUCTOR
	SideCard(const int& newValue = 0) : Card(newValue) {
		if (newValue < 0) {
			mCard.setFillColor(Color::Red);
		}
		if (newValue > 0) {
			mCard.setFillColor(Color::Blue);
		}
	}

	// DESTRUCTOR
	~SideCard();

	// METHODS
	void drawCardInWindow(RenderWindow& window) override;

};

