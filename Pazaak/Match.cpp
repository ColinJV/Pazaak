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
	gameBoard = new GameBoard();
	playerMainCards = new Card * [MAIN_HAND_SIZE];
	playerSideCards = new Card * [SIDE_HAND_SIZE];
	computerMainCards = new Card * [MAIN_HAND_SIZE];
	computerSideCards = new Card * [SIDE_HAND_SIZE];
	mPlayerCardsDealt = 0;
	mComputerCardsDealt = 0;
	mPlayerSetWins = 0;
	mComputerSetWins = 0;
	mPlayerScore = 0;
	mComputerScore = 0;

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
	for (int index = 0; index < 4; ++index) {
		int cardValue = rand() % 6 + 1;
		if (index < 2)	{
			if (index == -1) {
				cardValue *= -1;
			}
			playerSideCards[index] = new SideCard(cardValue);
			playerSideCards[index]->setPosition(gameBoard->getPlayerCardPosition(index + 9));

			cardValue = rand() % 6 + 1;
			if (index == -1) {
				cardValue *= -1;
			}
			computerSideCards[index] = new SideCard(cardValue);
			computerSideCards[index]->setPosition(gameBoard->getBotCardPosition(index + 9));
		}
		else {
			cardValue = rand() % 6 + 1;
			playerSideCards[index] = new SwitchCard(cardValue);
			playerSideCards[index]->setPosition(gameBoard->getPlayerCardPosition(index + 9));

			cardValue = rand() % 6 + 1;
			computerSideCards[index] = new SwitchCard(cardValue);
			computerSideCards[index]->setPosition(gameBoard->getBotCardPosition(index + 9));
		}
	}
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
int Match::playMatch(RenderWindow& window) {
	bool matchWinner = false, playerStands = false, computerStands = false;
	int winnerID = -1, player = 1;
	this->initializeSideDecks();

	while (window.isOpen() && !matchWinner) {
		if (window.isOpen() && player == 1 && !playerStands) {
			gameBoard->setTurnIndicator(player);
			// play startturn.wav sound
			dealMainCard(playerMainCards[mPlayerCardsDealt], player);
			// play drawmain.wav sound
			playerDecision(window, player, playerStands);
		}
		else if (window.isOpen() && player == 2 && !computerStands) {
			gameBoard->setTurnIndicator(player);
			// play startturn.wav sound
			dealMainCard(computerMainCards[mComputerCardsDealt], player);
			// play drawmain.wav sound
			// computerDecision();
		}
		if (playerStands && computerStands) {
			if (mPlayerScore > mComputerScore) {
				playerWinsASet();
			}
			else if (mComputerScore > mPlayerScore) {
				computerWinsASet();
			}
			else {
				// tied set
			}
			playerStands = false;
			computerStands = false;
			player = 1;
		}

		this->displayMatch(window);
	}
	return(winnerID);
}


/********************************************************************************************************
* Function: displayMatch()																				*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/18/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Clears the game window, draws all relevant Match data members on the window and displays	*
* the window.																							*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void Match::displayMatch(RenderWindow& window) {
	window.clear();
	gameBoard->display(window);
	this->drawAllCardsOnBoard(window);
	window.display();
}


/********************************************************************************************************
* Function: drawAllCardsOnBoard()																		*
* Date Created: 4/18/2024																				*
* Date Last Modified: 4/18/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Draws all Cards that are currently on the GameBoard.										*
* Input parameters: RenderWindow& window, a reference to the game window.								*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void Match::drawAllCardsOnBoard(RenderWindow& window) {
	for (int index = 0; index < MAIN_HAND_SIZE && playerMainCards[index] != nullptr; ++index) {
		playerMainCards[index]->drawCardInWindow(window);
	}
	
	for (int index = 0; index < MAIN_HAND_SIZE && computerMainCards[index] != nullptr; ++index) {
		computerMainCards[index]->drawCardInWindow(window);
	}

	for (int index = 0; index < SIDE_HAND_SIZE; ++index) {
		if (playerSideCards[index] != nullptr) {
			playerSideCards[index]->drawCardInWindow(window);
		}
	}

	for (int index = 0; index < SIDE_HAND_SIZE; ++index) {
		if (computerSideCards[index] != nullptr) {
			// need something here that draws the back of a card
			// could use art or just a different colored rectangle
			// the player is not supposed to know what the computer has
			// in its side deck.
		}
	}
}


/********************************************************************************************************
* Function: dealMainCard()																				*
* Date Created: 4/18/2024																				*
* Date Last Modified: 4/18/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Deals a MainCard into an array of Cards.													*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void Match::dealMainCard(Card*& newCardSlot, int& player) {
	int cardValue = rand() % 10 + 1;
	newCardSlot = new MainCard(cardValue);
	if (player == 1) {
		newCardSlot->setPosition(gameBoard->getPlayerCardPosition(mPlayerCardsDealt++));
	}
	else {
		newCardSlot->setPosition(gameBoard->getBotCardPosition(mComputerCardsDealt++));
	}
}


/********************************************************************************************************
* Function: playerDecision()																			*
* Date Created: 4/18/2024																				*
* Date Last Modified: 4/18/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Contains Event polling functionality for the player's turn. Can call a variety of		*
* functions based on player input, sets flags to avoid repeat actions. Loops until the game window		*
* closes, the player ends their turn, or the player stands.												*
* Input parameters: 1) RenderWindow& window, a reference to the game window. 2) int& player, a reference*
* to an integer representing which player's turn it is, the user or the computer. 3) bool& playerStands,*
* a reference to a boolean flag representing whether the user player has stood for the current set.		*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void Match::playerDecision(RenderWindow& window, int& player, bool& playerStands) {
	bool sideCardPlayed = false, alerted = false;
	while (window.isOpen() && player == 1) {

		if (mPlayerScore == 20) {
			playerStands = true;
			player = 2;
		}
		else if (mPlayerScore > 20) {
			// play bustwarning.wav
		}
		Event event;

		if (window.pollEvent(event) && !playerStands) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyReleased) {
				switch (event.key.code) {
				case Keyboard::Escape:
					window.close();
					break;
				case Keyboard::Num1:
					if (!sideCardPlayed) {
						playSideCard(playerSideCards[0], player);
						sideCardPlayed = true;
					}
					break;
				case Keyboard::Num2:
					if (!sideCardPlayed) {
						playSideCard(playerSideCards[1], player);
						sideCardPlayed = true;
					}
					break;
				case Keyboard::Num3:
					if (!sideCardPlayed) {
						playSideCard(playerSideCards[2], player);
						sideCardPlayed = true;
					}
					break;
				case Keyboard::Num4:
					if (!sideCardPlayed) {
						playSideCard(playerSideCards[3], player);
						sideCardPlayed = true;
					}
					break;
				case Keyboard::Num5:
					dynamic_cast <SwitchCard*> (playerSideCards[2])->modifyCard();
					break;
				case Keyboard::Num6:
					dynamic_cast <SwitchCard*> (playerSideCards[3])->modifyCard();
					break;
				case Keyboard::Enter:
					player = 2;
					break;
				case Keyboard::Backspace:
					playerStands = true;
					player = 2;
					break;
				default:
					break;
				}
			}
		}

		// if score == 20 playerStands = true;
		// if score > 20 && !alerted;
				// play bustwarning.wav
				// alerted = true;
				// if playerSideCards is empty
					// playerStands = true;


		this->displayMatch(window);
	}
}


void Match::playSideCard(Card*& sideCard, int& player) {
	if (sideCard != nullptr) {
		if (player == 1) {
			sideCard->setPosition(gameBoard->getPlayerCardPosition(mPlayerCardsDealt));
			playerMainCards[mPlayerCardsDealt++] = sideCard;
			sideCard = nullptr;
		}
		else {
			sideCard->setPosition(gameBoard->getBotCardPosition(mComputerCardsDealt));
			computerMainCards[mComputerCardsDealt++] = sideCard;
			sideCard = nullptr;
		}
	}
}


void Match::playerWinsASet() {
	gameBoard->setPlayerIndicator(++mPlayerSetWins);
}


void Match::computerWinsASet() {
	gameBoard->setBotIndicator(++mComputerSetWins);
}


void Match::updatePlayerScore() {

}