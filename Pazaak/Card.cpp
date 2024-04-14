#include "Card.hpp"

/********************************************************************************************************
* Function: Card constructor																			*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Constructs a Card object.																*
* Input parameters: int cardValue																		*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

Card::Card(const int& cardValue) {
	mValue = cardValue;
	mCard = RectangleShape(Vector2f(100.f, 200.f));
	mCard.setFillColor(Color::Black);
	mCard.setOutlineColor(Color::White);
	mCard.setOutlineThickness(3.f);
}


/********************************************************************************************************
* Function: Card destructor																				*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Destroys a Card object.																	*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

Card::~Card() {
	cout << "Inside Card destructor" << endl;
}


/********************************************************************************************************
* Function: getValue()																					*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Returns the value of a Card object.														*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

const int& Card::getValue(void) const {
	return(mValue);
}


/********************************************************************************************************
* Function: getColor()																					*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Returns the Color of a Card object.														*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

const Color& Card::getColor(void) const {
	return(mCard.getFillColor());
}


/********************************************************************************************************
* Function: setValue()																					*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Modifies the mValue data member of a Card object.										*
* Input parameters: int newValue																		*
* Returns: void																							*
* Preconditions: newValue != 0																			*
* Postconditions: None																					*
********************************************************************************************************/

void Card::setValue(int& newValue) {
	if (newValue != 0) {
		mValue = newValue;
	}
}


/********************************************************************************************************
* Function: setColor()																					*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Modifies the Color of a Card object.														*
* Input parameters: sf::Color newColor																	*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

void Card::setColor(Color& newColor) {
	mCard.setFillColor(newColor);
}