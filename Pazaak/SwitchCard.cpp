#include "SwitchCard.hpp"

/********************************************************************************************************
* Function: SwitchCard destructor																		*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Destroys a SwitchCard object.															*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

SwitchCard::~SwitchCard() {

}


/********************************************************************************************************
* Function: drawCardInWindow()																			*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Draws a SwitchCard object in a window.													*
* Input parameters: RenderWindow& window, a reference to a RenderWindow object where the SwitchCard		*
* object will be drawn.																					*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

void SwitchCard::drawCardInWindow(RenderWindow& window) {
	window.draw(this->mCard);
	// need something that draws a textbox indicating the SwitchCard's value
	// need something that draws a toggle +/- that indicates whether the value is positive or negative
}


/********************************************************************************************************
* Function: modifyCard()																				*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Multiplies the mValue data member of a SwitchCard by the mModifier data member.			*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

void SwitchCard::modifyCard(void) {
	mValue *= mModifier;
}