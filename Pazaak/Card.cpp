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
	if (!fontType.loadFromFile("Old_R.ttf")) {
		cout << "Failure to load font." << endl;
	}
	mValue = cardValue;
	mCard = RectangleShape(Vector2f(100.f, 125.f));
	mCard.setFillColor(Color::Black);
	mCard.setOutlineColor(Color::White);
	mCard.setOutlineThickness(3.f);
	mText.setFont(fontType);
	mText.setString(std::to_string(mValue));
	mText.setOutlineColor(Color::Black);
	mText.setOutlineThickness(2.f);
	mText.setCharacterSize(15);
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


/********************************************************************************************************
* Function: setPosition()																				*
* Date Created: 4/18/2024																				*
* Date Last Modified: 4/18/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Sets the position of the RectangleShape of a Card object to the Vector2f newPosition		*
* input, and the position of the Text of the Card object to an offset from newPosition.					*
* Input parameters: sf::Vector2f newPosition															*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void Card::setPosition(const Vector2f& newPosition) {
	mCard.setPosition(newPosition);
	mText.setPosition({ newPosition.x + 10, newPosition.y + 10 });
}


const RectangleShape& Card::getShape(void) const {
	return(mCard);
}

const Text& Card::getText(void) const {
	return(mText);
}