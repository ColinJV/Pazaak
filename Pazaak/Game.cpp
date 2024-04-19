#include "Game.hpp"

/********************************************************************************************************
* Function: Game constructor																			*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/17/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Constructs a Game object.																*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
Game::Game() {
	mGameWindow.create(VideoMode(1600, 900), "Pazaak Rules", sf::Style::Default);
	mGameWindow.setFramerateLimit(60);
	mPlayerWinCount = 0;
	mComputerWinCount = 0;
}


/********************************************************************************************************
* Function: Game destructor																				*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/17/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Destroys a Game object.																	*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
Game::~Game() {
	
}


/********************************************************************************************************
* Function: runGame()																					*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/17/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Creates a MainMenu object and calls runMainMenu(). If runMainMenu() returns true, creates*
* a Match object and calls playMatch(). When playMatch returns, increments either playerWinCount or		*
* computerWinCount depending on return value. Loops until gameWindow closes then returns.				*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void Game::runGame() {
	MainMenu mainMenu;
	unsigned int winner = -1;

	while (mGameWindow.isOpen()) {
		bool playGame = false;
		playGame = mainMenu.runMainMenu(mGameWindow);
		if (playGame == true) {
			// Match newMatch;
			// winner = newMatch.playMatch(mGameWindow);
			if (winner == PLAYER_WINS) {
				this->playerVictory();
				// play sound effect of Niklos whining about losing
			}
			else {
				this->computerVictory();
				// play sound effect of Niklos gloating
			}
		}
	}
}


/********************************************************************************************************
* Function: playerVictory()																				*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/17/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Increments the mPlayerWinCount data member.												*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void Game::playerVictory() {
	++mPlayerWinCount;
}


/********************************************************************************************************
* Function: computerVictory()																			*
* Date Created: 4/17/2024																				*
* Date Last Modified: 4/17/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Increments the mComputerWinCount data member.											*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void Game::computerVictory() {
	++mComputerWinCount;
}