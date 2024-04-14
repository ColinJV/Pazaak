#pragma once
#include "SideCard.hpp"

class SwitchCard : public SideCard {
public:
	// CONSTRUCTOR
	SwitchCard(const int& newValue = 0) : SideCard(newValue) {
		mModifier = -1;
	}

	// DESTRUCTOR
	~SwitchCard();

	// METHODS
	void displayCard(RenderWindow& window) override;
	void modifyCard(void);

private:
	int mModifier;
};


