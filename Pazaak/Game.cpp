#include "Game.hpp"

/********************************************************************************************************
* Function: Game constructor
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Constructs a Game object.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
Game::Game() {
	mGameWindow.create(VideoMode(1600, 900), "Pazaak Rules", sf::Style::Default);
	mGameWindow.setFramerateLimit(60);
	mPlayerWinCount = 0;
	mComputerWinCount = 0;
}


/********************************************************************************************************
* Function: Game destructor
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Destroys a Game object.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
Game::~Game() {
	
}


/********************************************************************************************************
* Function: runGame()
* Date Created: 4/17/2024
* Date Last Modified: 4/22/2024
* Programmer: Colin Van Dyke, Nick McBrayer
* Description: Creates a MainMenu object and calls runMainMenu(). If runMainMenu() returns true, creates
* a Match object and calls playMatch(). When playMatch returns, increments either playerWinCount or
* computerWinCount depending on return value. Loops until gameWindow closes then returns.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Game::runGame() {
	MainMenu mainMenu;
	int winner = -1;
	Niklos.setBuffer(NiklosBuff);
	Niklos.setVolume(30);
	while (mGameWindow.isOpen()) {
		bool playGame = false;
		playGame = mainMenu.runMainMenu(mGameWindow);
		if (playGame == true) {
			Match newMatch;
			winner = newMatch.playMatch(mGameWindow);
			if (winner == PLAYER_WINS) {
				playerVictory();
				if (mPlayerWinCount == 1) {
					NiklosBuff.loadFromFile("audio/Niklos_lose1.wav");
					Niklos.play();
				}
				else if (mPlayerWinCount == 2) {
					NiklosBuff.loadFromFile("audio/Niklos_lose2.wav");
					Niklos.play();
				}
				else if (mPlayerWinCount >= 3) {
					NiklosBuff.loadFromFile("audio/Niklos_lose3.wav");
					Niklos.play();
				}
			}
			else {
				computerVictory();
				NiklosBuff.loadFromFile("audio/Niklos_win.wav");
				Niklos.play();
			}
		}
	}
}


/********************************************************************************************************
* Function: playerVictory()
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Increments the mPlayerWinCount data member.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Game::playerVictory() {
	++mPlayerWinCount;
}


/********************************************************************************************************
* Function: computerVictory()
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Increments the mComputerWinCount data member.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void Game::computerVictory() {
	++mComputerWinCount;
}