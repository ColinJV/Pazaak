#include "Match.hpp"

/********************************************************************************************************
* Function: Match constructor
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Constructs a Match object. Instantiates four arrays of pointers to Cards on
* the heap, setting the pointers to Cards to nullptr initially. Instantiates a Board object.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
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
* Function: Match destructor
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Destroys a Match object.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
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
* Function: initializeSideDecks()
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Generates SideCards and SwitchCards for the Player and Computer's Side Decks.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::initializeSideDecks() {
	for (int index = 0; index < 4; ++index) {
		int cardValue = rand() % 6 + 1;
		if (index < 2)	{
			if (index == 1) {
				cardValue *= -1;
			}
			playerSideCards[index] = new SideCard(cardValue);
			playerSideCards[index]->setPosition(gameBoard->getPlayerCardPosition(index + 9));

			cardValue = rand() % 6 + 1;
			if (index == 1) {
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
* Function: playMatch()
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Contains main flow of game logic.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
int Match::playMatch(RenderWindow& window) {
	bool matchWinner = false, playerStands = false, computerStands = false;
	int winnerID = -1, player = 1, setWinner = -1;
	this->initializeSideDecks();

	while (window.isOpen() && !matchWinner) {
		if (window.isOpen() && player == 1 && !playerStands) {
			gameBoard->setTurnIndicator(player);
			// play startturn.wav sound
			dealMainCard(playerMainCards[mPlayerCardsDealt], player);
			// play drawmain.wav sound
			playerDecision(window, player, playerStands, computerStands);
			if (mPlayerScore > 20) {
				computerStands = true;
			}
		}
		player = 2;
		if (window.isOpen() && player == 2 && !computerStands) {
			gameClock.restart();
			gameBoard->setTurnIndicator(player);
			// play startturn.wav sound
			dealMainCard(computerMainCards[mComputerCardsDealt], player);
			// play drawmain.wav sound
			while (gameClock.getElapsedTime() < sf::milliseconds(1000)) {
				this->displayMatch(window);
			}
			computerDecision(window, player, computerStands, playerStands);
			if (mComputerScore > 20) {
				playerStands = true;
			}
		}
		player = 1;
		if (playerStands && computerStands) {
			setWinner = determineWinner();
			incrementWins(setWinner);
			if (!matchWinnerExists()) {
				switch (setWinner) {
				case 1:
					// play winset.wav
					break;
				case 2:
					// play loseset.wav
					break;
				default:
					break;
				}
				displaySetWinMessage(setWinner, window);

				playerStands = false;
				computerStands = false;
				setWinner = -1;
				resetSet();
			}
			else {
				matchWinner = true;
				// if setWinner == 1 play winmatch.wav
				// if setWinner == 2 play losematch.wav
				displayMatchWinMessage(setWinner, window);
				winnerID = setWinner;
			}
		}

		this->displayMatch(window);
	}

	return(winnerID);
}


/********************************************************************************************************
* Function: displayMatch()
* Date Created: 4/17/2024
* Date Last Modified: 4/18/2024
* Programmer: Colin Van Dyke
* Description: Clears the game window, draws all relevant Match data members on the window and displays
* the window.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::displayMatch(RenderWindow& window) {
	window.clear();
	gameBoard->display(window);
	this->drawAllCardsOnBoard(window);
	window.display();
}


/********************************************************************************************************
* Function: drawAllCardsOnBoard()
* Date Created: 4/18/2024
* Date Last Modified: 4/18/2024
* Programmer: Colin Van Dyke
* Description: Draws all Cards that are currently on the GameBoard.
* Input parameters: RenderWindow& window, a reference to the game window.
* Returns: void
* Preconditions: None
* Postconditions: None
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
* Function: dealMainCard()
* Date Created: 4/18/2024
* Date Last Modified: 4/18/2024
* Programmer: Colin Van Dyke
* Description: Deals a MainCard into an array of Cards.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::dealMainCard(Card*& newCardSlot, int& player) {
	int cardValue = rand() % 10 + 1;
	newCardSlot = new MainCard(cardValue);
	if (player == 1) {
		newCardSlot->setPosition(gameBoard->getPlayerCardPosition(mPlayerCardsDealt++));
		mPlayerScore += cardValue;
		// something here that updates the Text in the score window
	}
	else {
		newCardSlot->setPosition(gameBoard->getBotCardPosition(mComputerCardsDealt++));
		mComputerScore += cardValue;
		// something here that updates the Text in the score window
	}
}


/********************************************************************************************************
* Function: playerDecision()
* Date Created: 4/18/2024
* Date Last Modified: 4/18/2024
* Programmer: Colin Van Dyke
* Description: Contains Event polling functionality for the player's turn. Can call a variety of
* functions based on player input, sets flags to avoid repeat actions. Loops until the game window
* closes, the player ends their turn, or the player stands.
* Input parameters: 1) RenderWindow& window, a reference to the game window. 2) int& player, a reference
* to an integer representing which player's turn it is, the user or the computer. 3) bool& playerStands,
* a reference to a boolean flag representing whether the user player has stood for the current set.
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::playerDecision(RenderWindow& window, int& player, bool& playerStands, bool& computerStands) {
	bool sideCardPlayed = false, alerted = false;

	while (window.isOpen() && player == 1) {

		if (mPlayerScore == 20) {
			playerStands = true;
			player = 2;
		}
		else if (mPlayerScore < 20 && mPlayerCardsDealt == 9) {
			playerStands = true;
			computerStands = true;
			player = 2;
		}
		else if (mPlayerScore > 20 && !alerted) {
			// play bustwarning.wav
			alerted = true;
			if (!playerHasSideCards()) {
				playerStands = true;
				player = 2;
			}
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
					if (mPlayerScore > 20) {
						playerStands = true;
					}
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

		this->displayMatch(window);
	}
}


/********************************************************************************************************
* Function: playSideCard()
* Date Created: 4/18/2024
* Date Last Modified: 4/18/2024
* Programmer: Colin Van Dyke
* Description: Plays a SideCard at the address of the input reference to a Card*, updates the score of
* the player who played the card, and sets the original pointer to nullptr.
* Input parameters: 1) Card*& sideCard, a reference to a pointer to a Card that is going to be played to
* the board. 2) const int& player, a reference to an integer representing which player is playing the
* card.
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::playSideCard(Card*& sideCard, const int& player) {
	if (sideCard != nullptr) {
		if (player == 1) {
			sideCard->setPosition(gameBoard->getPlayerCardPosition(mPlayerCardsDealt));
			playerMainCards[mPlayerCardsDealt++] = sideCard;
			mPlayerScore += sideCard->getValue();
			sideCard = nullptr;
		}
		else {
			sideCard->setPosition(gameBoard->getBotCardPosition(mComputerCardsDealt));
			computerMainCards[mComputerCardsDealt++] = sideCard;
			mComputerScore += sideCard->getValue();
			sideCard = nullptr;
		}
	}
}


/********************************************************************************************************
* Function: playerWinsASet()
* Date Created: 4/18/2024
* Date Last Modified: 4/18/2024
* Programmer: Colin Van Dyke
* Description: Updates the win count indicators on the game board and increments the player's win counter.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::playerWinsASet() {
	gameBoard->setPlayerIndicator(++mPlayerSetWins);
}


/********************************************************************************************************
* Function: computerWinsASet()
* Date Created: 4/18/2024
* Date Last Modified: 4/18/2024
* Programmer: Colin Van Dyke
* Description: Updates the win count indicators on the game board and increments the computer's win counter.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::computerWinsASet() {
	gameBoard->setBotIndicator(++mComputerSetWins);
}


/********************************************************************************************************
* Function: playerHasSideCards()
* Date Created: 4/19/2024
* Date Last Modified: 4/19/2024
* Programmer: Colin Van Dyke
* Description: Iterates through the player's Side Deck and returns a boolean indicating whether the player
* has any Side Cards left, true if yes, false if no.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
bool Match::playerHasSideCards() {
	bool sideCardExists = false;
	for (int index = 0; index < SIDE_HAND_SIZE && !sideCardExists; ++index) {
		if (playerSideCards[index] != nullptr) {
			sideCardExists = true;
		}
	}
	return(sideCardExists);
}


/********************************************************************************************************
* Function: computerHasSideCards()
* Date Created: 4/19/2024
* Date Last Modified: 4/19/2024
* Programmer: Colin Van Dyke
* Description: Iterates through the computer's Side Deck and returns a boolean indicating whether the computer
* has any Side Cards left, true if yes, false if no.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
bool Match::computerHasSideCards() {
	bool sideCardExists = false;
	for (int index = 0; index < SIDE_HAND_SIZE && !sideCardExists; ++index) {
		if (computerSideCards[index] != nullptr) {
			sideCardExists = true;
		}
	}
	return(sideCardExists);
}


/********************************************************************************************************
* Function: computerDecision()
* Date Created: 4/19/2024
* Date Last Modified: 4/19/2024
* Programmer: Colin Van Dyke
* Description: Primary controller for logic behind the computer player's decisions. Computer will stand,
* end turn, or use a side card based on various conditions related to the computer's score, the player's
* score, 
* Input parameters: 1) RenderWindow& window, a reference to the game window. 2) int& player, a reference
* to an integer representing which player has the current turn (should be the computer until it ends turn).
* 3) bool& computerStands, a reference to a boolean representing whether the computer player has stood.
* 4) bool& playerStands, a reference to a boolean representing whether the user controlled player has stood.
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::computerDecision(RenderWindow& window, int& player, bool& computerStands, bool& playerStands) {
	bool sideCardPlayed = false, alerted = false;
	gameClock.restart();
	while (window.isOpen() && player == 2) {

		if (mComputerScore > mPlayerScore && mComputerScore <= 20 && playerStands) {
			computerStands = true;
		}
		else if (mComputerScore < 20 && mComputerCardsDealt == 9) {
			computerStands = true;
			playerStands = true;
		}
		if (!computerStands && playerStands && mPlayerScore > 20) {
			computerStands = true;
			player = 1;
		}
		if (!computerStands && mComputerScore >= 18 && mComputerScore < 20) {
			computerStands = true;
			player = 1;
		}
		else if (mComputerScore > 20) {
			if (!alerted) {
				// play warnbust.wav
				alerted = true;
			}
			if (!computerHasSideCards()) {
				computerStands = true;
				player = 1;
			}
		}

		// this is here in case the player closes the window during the computer's turn
		Event event;
		if (window.pollEvent(event) && !computerStands) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyReleased) {
				switch (event.key.code) {
				case Keyboard::Escape:
					window.close();
					break;
				default:
					break;
				}
			}
		}

		if (mComputerScore < 14) {
			player = 1;
		}
		else {
			if (computerHasSideCards() && !sideCardPlayed) {
				computerChooseToPlaySideCards(sideCardPlayed);
				player = 1;
				if (mComputerScore >= 18) {
					computerStands = true;
				}
			}
		}

		this->displayMatch(window);
	}

	while (window.isOpen() && gameClock.getElapsedTime() < sf::milliseconds(1200)) {
		this->displayMatch(window);
	}
}


/********************************************************************************************************
* Function: computerChooseToPlaySideCards()
* Date Created: 4/19/2024
* Date Last Modified: 4/19/2024
* Programmer: Colin Van Dyke
* Description: Determines whether the computer will use a Side Card. If the computer can reach 20 points by
* using a Side Card it will do so.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::computerChooseToPlaySideCards(bool& sideCardPlayed) {
	int goal = 20 - mComputerScore;
	int sideValues[SIDE_HAND_SIZE] = { 0 };
	for (int index = 0; index < SIDE_HAND_SIZE; ++index) {
		if (computerSideCards[index] != nullptr) {
			sideValues[index] = computerSideCards[index]->getValue();
		}
	}
	for (int index = 0; index < SIDE_HAND_SIZE && !sideCardPlayed; ++index) {
		if (goal == sideValues[index] && goal != 0) {
			playSideCard(computerSideCards[index], 2);
			sideCardPlayed = true;
		}
		else if (index > 1 && goal != 0 && goal == (sideValues[index] * (-1))) {
			dynamic_cast <SwitchCard*> (computerSideCards[index])->modifyCard();
			playSideCard(computerSideCards[index], 2);
			sideCardPlayed = true;
		}
	}
}


/********************************************************************************************************
* Function: resetSet()
* Date Created: 4/19/2024
* Date Last Modified: 4/19/2024
* Programmer: Colin Van Dyke
* Description: Clears the game board of cards and returns it into a condition to begin a set. Resets
* integer counters for cards dealt and score for both the player and computer to 0.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::resetSet() {
	for (int index = 0; index < MAIN_HAND_SIZE; ++index) {
		if (playerMainCards[index] != nullptr) {
			delete playerMainCards[index];
			playerMainCards[index] = nullptr;
		}
		if (computerMainCards[index] != nullptr) {
			delete computerMainCards[index];
			computerMainCards[index] = nullptr;
		}
	}
	mPlayerCardsDealt = 0;
	mComputerCardsDealt = 0;
	mPlayerScore = 0;
	mComputerScore = 0;
}


/********************************************************************************************************
* Function: determineWinner()
* Date Created: 4/19/2024
* Date Last Modified: 4/19/2024
* Programmer: Colin Van Dyke
* Description: Determines which player has won a set based on various win conditions.
* Input parameters: void
* Returns: int winner, will be 1 if the user player has won the set, 2 if the computer has won the set.
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
int Match::determineWinner() {
	int winner = -1;
	if (mPlayerScore == mComputerScore && mPlayerScore <= 20) {
		winner = 0;
	}
	else if (mPlayerScore > mComputerScore && mPlayerScore <= 20 ||
		(mComputerScore > 20 && mPlayerScore <= 20)) {
		winner = 1;
	}
	else if (mComputerScore > mPlayerScore && mComputerScore <= 20 ||
		(mPlayerScore > 20 && mComputerScore <= 20)) {
		winner = 2;
	}

	if (mPlayerCardsDealt == 9 && mPlayerScore <= 20) {
		winner = 1;
	}
	else if (mComputerCardsDealt == 9 && mComputerScore <= 20) {
		winner = 2;
	}
	return(winner);
}


/********************************************************************************************************
* Function: incrementWins()
* Date Created: 4/19/2024
* Date Last Modified: 4/19/2024
* Programmer: Colin Van Dyke
* Description: Increments the set win count of either player and sets the visual indicator correctly based
* on the value of the input parameter.
* Input parameters: int& winner, a reference to an integer representing which player has won the set. If
* the value is 1, the player has won. If the value is 2, the computer has won the set.
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::incrementWins(int& winner) {
	if (winner == 1) {
		gameBoard->setPlayerIndicator(++mPlayerSetWins);
	}
	else if (winner == 2) {
		gameBoard->setBotIndicator(++mComputerSetWins);
	}
}


/********************************************************************************************************
* Function: matchWinnerExists()
* Date Created: 4/19/2024
* Date Last Modified: 4/19/2024
* Programmer: Colin Van Dyke
* Description: Checks the set win count of both players to see if one of them has won the match. Returns
* true if one has, false if neither has.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
bool Match::matchWinnerExists() {
	bool winnerExists = false;
	if (mPlayerSetWins == 3) {
		winnerExists = true;
	}
	else if (mComputerSetWins == 3) {
		winnerExists = true;
	}
	return(winnerExists);
}


/********************************************************************************************************
* Function: displaySetWInMessage()
* Date Created: 4/20/2024
* Date Last Modified: 4/20/2024
* Programmer: Colin Van Dyke
* Description: Creates RectangleShape and Text to display a system message indicating the outcome of a set.
* Input parameters: 1) int& setWinner, a reference to an integer indicating which player has won the set.
* 2) RenderWindow& window, a reference to the game window.
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::displaySetWinMessage(int& setWinner, RenderWindow& window) {
	bool acknowledged = false;
	RectangleShape systemMessage({500.f, 250.f});
	systemMessage.setPosition(540.f, 300.f);
	systemMessage.setFillColor(Color(0, 0, 170, 150));
	systemMessage.setOutlineColor(Color(0, 166, 248, 255));
	Text systemMessageText;
	Font fontType;
	if (!fontType.loadFromFile("Old_R.ttf")) {
		cout << "Error loading font." << endl;
	}
	systemMessageText.setFont(fontType);
	systemMessageText.setFillColor(Color(0, 166, 248, 255));
	systemMessageText.setOutlineColor(Color(0, 166, 248, 255));
	systemMessageText.setPosition(560.f, 390.f);
	systemMessageText.setCharacterSize(20);
	if (setWinner == 0) {
		systemMessageText.setString("The set is tied.\nPress Enter to continue.");
	}
	else if (setWinner == 1) {
		systemMessageText.setString("You win the set.\nPress Enter to continue.");
	}
	else if (setWinner == 2) {
		systemMessageText.setString("You lose the set.\nPress Enter to continue.");
	}

	while (window.isOpen() && !acknowledged) {

		Event event;
		if (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyReleased) {
				switch (event.key.code) {
				case Keyboard::Enter:
					acknowledged = true;
					break;
				default:
					break;
				}
			}
		}


		window.clear();
		gameBoard->display(window);
		this->drawAllCardsOnBoard(window);
		window.draw(systemMessage);
		window.draw(systemMessageText);
		window.display();
	}
	
}


/********************************************************************************************************
* Function: displayMatchWinMessage()
* Date Created: 4/20/2024
* Date Last Modified: 4/20/2024
* Programmer: Colin Van Dyke
* Description: Creates RectangleShape and Text to display a system message indicating the outcome of a match.
* Input parameters: 1) int& setWinner, a reference to an integer indicating which player has won the match.
* 2) RenderWindow& window, a reference to the game window.
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Match::displayMatchWinMessage(int& setWinner, RenderWindow& window) {
	bool acknowledged = false;
	RectangleShape systemMessage({ 500.f, 250.f });
	systemMessage.setPosition(540.f, 300.f);
	systemMessage.setFillColor(Color(0, 0, 170, 150));
	systemMessage.setOutlineColor(Color(0, 166, 248, 255));
	Text systemMessageText;
	Font fontType;
	if (!fontType.loadFromFile("Old_R.ttf")) {
		cout << "Error loading font." << endl;
	}
	systemMessageText.setFont(fontType);
	systemMessageText.setFillColor(Color(0, 166, 248, 255));
	systemMessageText.setOutlineColor(Color(0, 166, 248, 255));
	systemMessageText.setPosition(560.f, 390.f);
	systemMessageText.setCharacterSize(20);
	if (setWinner == 1) {
		systemMessageText.setString("You win the match!\nPress Enter to continue.");
	}
	else if (setWinner == 2) {
		systemMessageText.setString("You lose the match!\nPress Enter to continue.");
	}

	while (window.isOpen() && !acknowledged) {

		Event event;
		if (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyReleased) {
				switch (event.key.code) {
				case Keyboard::Enter:
					acknowledged = true;
					break;
				default:
					break;
				}
			}
		}


		window.clear();
		gameBoard->display(window);
		this->drawAllCardsOnBoard(window);
		window.draw(systemMessage);
		window.draw(systemMessageText);
		window.display();
	}

}