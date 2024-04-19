#include "Match.hpp"

/********************************************************************************************************
* Function: Match constructor																			*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/17/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Constructs a Match object. Instantiates four arrays of pointers to pointers to Cards on	*
* the heap, setting the pointers to Cards to nullptr initially. Instantiates a Board object.			*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
Match::Match() {
	playerMainCards = new Card * [MAIN_HAND_SIZE];
	playerSideCards = new Card * [SIDE_HAND_SIZE];
	computerMainCards = new Card * [MAIN_HAND_SIZE];
	computerSideCards = new Card * [SIDE_HAND_SIZE];
	playerCardsDealt = 0;
	computerCardsDealt = 0;

	for (int index = 0; index < MAIN_HAND_SIZE; ++index) {
		playerMainCards[index] = nullptr;
		computerMainCards[index] = nullptr;
	}
	for (int index = 0; index < SIDE_HAND_SIZE; ++index) {
		playerSideCards[index] = nullptr;
		computerSideCards[index] = nullptr;
	}
}


/********************************************************************************************************
* Function: Match destructor																			*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/17/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Destroys a Match object.																	*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
Match::~Match() {
	for (int index = 0; index < MAIN_HAND_SIZE; ++index) {
		delete playerMainCards[index];
		delete computerMainCards[index];
	}
	for (int index = 0; index < SIDE_HAND_SIZE; ++index) {
		delete playerSideCards[index];
		delete computerSideCards[index];
	}
}


/********************************************************************************************************
* Function: initializeSideDecks()																		*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/17/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Generates SideCards and SwitchCards for the Player and Computer's Side Decks.			*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void Match::initializeSideDecks() {
	int cardValue = rand() % 6 + 1;
	playerSideCards[0] = new SideCard(cardValue);
	// put playerSideCards[0] in correct position
	// put playerSideCards[0] text in correct position
	cardValue = rand() % 6 + 1;
	computerSideCards[0] = new SideCard(cardValue);
	// put in correct position
	// put text in correct position
	cardValue = ((rand() % 6) * (-1)) - 1;
	playerSideCards[1] = new SideCard(cardValue);
	// put in correct position
	// put text in correct position
	cardValue = ((rand() % 6) * (-1)) - 1;
	computerSideCards[1] = new SideCard(cardValue);
	// put in correct position
	// put text in correct position
	cardValue = rand() % 6 + 1;
	playerSideCards[2] = new SwitchCard(cardValue);
	// put in correct position
	// put text in correct position
	cardValue = rand() % 6 + 1;
	computerSideCards[2] = new SwitchCard(cardValue);
	// put in correct position
	// put text in correct position
	cardValue = ((rand() % 6) * (-1)) - 1;
	playerSideCards[3] = new SwitchCard(cardValue);
	// put in correct position
	// put text in correct position
	cardValue = ((rand() % 6) * (-1)) - 1;
	computerSideCards[3] = new SwitchCard(cardValue);
}


/********************************************************************************************************
* Function: playMatch()																					*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/17/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Contains main flow of game logic.														*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
unsigned int Match::playMatch(RenderWindow& window) {
	bool matchWinner = false;
	unsigned int winnerID = -1, turn = 1, playerSetWins = 0, computerSetWins = 0;
	while (window.isOpen() && !matchWinner) {
		if (turn == 1) {
			// do player turn stuff
		}
		else if (turn == 2) {
			// do AI stuff
		}


		this->displayMatch(window);
	}

}


void Match::displayMatch(RenderWindow& window) {
	// gameBoard->drawBoard(window);
	// drawAllCardsOnBoard();
	window.display();

}