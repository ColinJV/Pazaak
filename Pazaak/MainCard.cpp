#include "MainCard.hpp"

/********************************************************************************************************
* Function: MainCard destructor																			*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Destroys a MainCard object.																*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

MainCard::~MainCard() {
	std::cout << "Inside MainCard destructor." << std::endl;
}


/********************************************************************************************************
* Function: displayCard()																				*
* Date Created: 4/13/2024																				*
* Date Last Modified: 4/13/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Draws a MainCard object in a window.														*
* Input parameters: RenderWindow& window, a reference to a RenderWindow in which the MainCard is being	*
* drawn.																								*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/

void MainCard::drawCardInWindow(RenderWindow& window) {
	window.draw(this->mCard);
	window.draw(this->mText);
}