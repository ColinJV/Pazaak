#include "SideCard.hpp"

/********************************************************************************************************
* Function: SideCard destructor																			*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Destroys a SideCard object.																*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

SideCard::~SideCard() {
	cout << "Inside SideCard destructor" << endl;
}


/********************************************************************************************************
* Function: drawCardInWindow()																			*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Draws a SideCard object in a window.														*
* Input parameters: sf::RenderWindow& window, a reference to a RenderWindow where the SideCard object	*
* will be drawn.																						*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

void SideCard::drawCardInWindow(RenderWindow& window) {
	window.draw(this->mCard);
	// need to draw a text box on the card that indicates its value
}