#include "MainMenu.hpp"

/********************************************************************************************************
* Function: MainMenu constructor
* Date Created: 4/14/2024
* Date Last Modified: 4/20/2024
* Programmer: Colin Van Dyke, Nick McBrayer
* Description: Constructs a MainMenu object.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
MainMenu::MainMenu() {
	if (!fontType.loadFromFile("Old_R.ttf")) {
		cout << "Font not found in project path." << endl;
	}
	
	backgroundImage.setSize(Vector2f(1600, 900));
	backgroundImage.setPosition(0, 0);
	backgroundTexture.loadFromFile("splashMenu.png");
	backgroundImage.setTexture(&backgroundTexture);

	mainMenuText = new Text[NUMBER_OF_OPTIONS];

	// Play
	mainMenuText[0].setFont(fontType);
	mainMenuText[0].setFillColor(Color::Yellow);
	mainMenuText[0].setString("1. Play Game");
	mainMenuText[0].setCharacterSize(20);
	mainMenuText[0].setPosition(800, 425);

	// Rules
	mainMenuText[1].setFont(fontType);
	mainMenuText[1].setFillColor(Color(0, 166, 248, 255));
	mainMenuText[1].setString("2. Rules");
	mainMenuText[1].setCharacterSize(20);
	mainMenuText[1].setPosition(835, 490);

	// Quit
	mainMenuText[2].setFont(fontType);
	mainMenuText[2].setFillColor(Color(0, 166, 248, 255));
	mainMenuText[2].setString("3. Quit");
	mainMenuText[2].setCharacterSize(20);
	mainMenuText[2].setPosition(850, 560);

	// Sounds
	if (!background.openFromFile("audio/mus_theme_cult.wav")) {
		cout << "Main Theme Error!" << endl;
	}
	if (!moveBuf.loadFromFile("audio/kotor_menu_sfx2.wav")) {
		cout << "Menu move Sound Error!" << endl;
	}
	if (!selBuff.loadFromFile("audio/kotor_menu_sfx.wav")) {
		cout << "Menu select Error!" << endl;
	}
	menuMove.setBuffer(moveBuf);
	menuSelect.setBuffer(selBuff);

	userSelection = 0;
}


/********************************************************************************************************
* Function: MainMenu destructor
* Date Created: 4/14/2024
* Date Last Modified: 4/14/2024
* Programmer: Colin Van Dyke
* Description: Destroys a MainMenu object.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
MainMenu::~MainMenu() {
	delete[] mainMenuText;
}


/********************************************************************************************************
* Function: drawMainMenu()
* Date Created: 4/14/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Draws the MainMenu text on the input RenderWindow
* Input parameters: RenderWindow& window, a reference to a RenderWindow that is the game's graphics
* window.
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void MainMenu::drawMainMenu(RenderWindow& window) {
	window.draw(backgroundImage);

	for (int index = 0; index < 3; ++index) {
		window.draw(mainMenuText[index]);
	}
}


/********************************************************************************************************
* Function: moveUp()
* Date Created: 4/14/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Modifies which option on the main menu is highlighted and decrements the userSelection
* member variable of MainMenu. Checks if userSelection is out of bounds and corrects it if it is.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void MainMenu::moveUp() {
	if (userSelection >= 0) {
		mainMenuText[userSelection--].setFillColor(Color(0, 166, 248, 255));
		if (userSelection == -1) {
			userSelection = 2;
		}
		mainMenuText[userSelection].setFillColor(Color::Yellow);
	}
}


/********************************************************************************************************
* Function: moveDown()
* Date Created: 4/14/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Modifies which option on the main menu is highlighted and increments the userSelection
* member variable of MainMenu. Checks if userSelection is out of bounds and corrects it if it is.
* Input parameters: int cardValue
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void MainMenu::moveDown() {
	if (userSelection <= NUMBER_OF_OPTIONS) {
		mainMenuText[userSelection++].setFillColor(Color(0, 166, 248, 255));
		if (userSelection == NUMBER_OF_OPTIONS) {
			userSelection = 0;
		}
		mainMenuText[userSelection].setFillColor(Color::Yellow);
	}
}


/********************************************************************************************************
* Function: drawRules()
* Date Created: 4/14/2024
* Date Last Modified: 4/14/2024
* Programmer: Colin Van Dyke
* Description: Creates 3 sf::Text objects; a rules header, rules text, and controls header. Applies
* settings for the text then draws it and displays it to the window, reading user inputs until either
* the user elects to return to the Main Menu or the window closes.
* Input parameters: RenderWindow& window, a reference to the RenderWindow object that is the game window.
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void MainMenu::drawRules(RenderWindow& window) const
{
	Text rules;
	Text rulesHeader;
	Text controlsHeader;
	bool finishedReading = false;

	rulesHeader.setFont(fontType);
	rulesHeader.setFillColor(Color(0, 166, 248, 255));
	rulesHeader.setString("Pazaak Rules");
	rulesHeader.setCharacterSize(30);
	rulesHeader.setPosition(50, 50);

	rules.setFont(fontType);
	rules.setFillColor(Color(0, 166, 248, 255));
	rules.setString("Pazaak is a two player card game.\n"
		"At the beginning of a turn, the player draws a card from the Main Deck onto their board.\n"
		"Cards drawn from the Main Deck can have a value between 1 and 10.\n"
		"After drawing a card from the Main Deck, the player may elect to use a card from their Side Deck.\n"
		"Side Deck cards can be used to increase or decrease your total score.\n"
		"Side Card 1 increases your score. Side Card 2 decreases your score.\n"
		"Side Cards 3 and 4 can increase or decrease your score, depending on your choice.\n"
		"A player may use only one card from their Side Deck per turn at most.\n"
		"Upon playing a card from the Side Deck, or choosing not to, the player may end their turn or stand.\n"
		"Standing will end all your action for the current set.\n"
		"The objective is to reach a total score of 20 without exceeding 20, a.k.a. busting.\n"
		"A bust occurs when a player's turn ends when they have more than 20 points.\n"
		"If your score exceeds 20 and is then reduced by playing a card from the Side Deck,\n"
		"a bust has not occurred and play will continue.\n"
		"If a player busts, their opponent wins the set automatically.\n"
		"If a player reaches 20 points, they stand automatically.\n"
		"If a player has 9 cards on their board and has not busted, they win the set automatically.\n"
		"The first player to win three sets wins the match.\n\n\n\n"
		"Enter to End Turn. Backspace to Stand and end your action for the current set.\n"
		"'1', '2', '3', and '4' keys to use your Side Deck cards 1-4 respectively.\n"
		"The '5' and '6' keys will modify the value of your third or fourth\n"
		"Side Deck cards, switching the sign between positive and negative.\n\n\n"
		"Press Enter/Spacebar to return to the Main Menu.");
	rules.setPosition(70, 100);
	rules.setCharacterSize(15);

	controlsHeader.setFont(fontType);
	controlsHeader.setFillColor(Color::Yellow);
	controlsHeader.setString("Controls");
	controlsHeader.setCharacterSize(30);
	controlsHeader.setPosition(50, 580);

	while (!finishedReading && window.isOpen()) {
		Event event;

		if (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyReleased) {
				switch (event.key.code) {
				case Keyboard::Enter:
					finishedReading = true;
					break;
				case Keyboard::Space:
					finishedReading = true;
					break;
				case Keyboard::Escape:
					window.close();
					break;
				}
			}
		}
		window.clear();

		window.draw(rulesHeader);
		window.draw(rules);
		window.draw(controlsHeader);

		window.display();
	}
}


/********************************************************************************************************
* Function: getUserSelection()
* Date Created: 4/14/2024
* Date Last Modified: 4/14/2024
* Programmer: Colin Van Dyke
* Description: Creates two sf::Text objects, one for a header and one for the rule text. Sets settings
* for the text then draws it and displays it to the window, reading user inputs until either the user
* elects to return to the Main Menu or the window closes.
* Input parameters: RenderWindow& window, a reference to the RenderWindow object that is the game window.
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
int MainMenu::getUserSelection() {
	return(userSelection);
}


/********************************************************************************************************
* Function: runMainMenu()
* Date Created: 4/14/2024
* Date Last Modified: 4/20/2024
* Programmer: Colin Van Dyke, Nick McBrayer
* Description: Main logic function for MainMenu object. Draws and displays the MainMenu to the window
* and conducts event polling. Highlights various menu options based on userSelection value. Loops until
* the window closes or until the player chooses to play the game, at which point a boolean flag is set
* and returned to the calling function.
* Input parameters: RenderWindow& window, a reference to the RenderWindow object that is the game window.
* Returns: bool playGame, a boolean flag that controls loop repetition and, when returned to the calling
* function, will initiate the primary gameplay logic.
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
bool MainMenu::runMainMenu(RenderWindow& window) {
	bool playGame = false;

	background.setVolume(20);
	background.setLoop(true);
	background.play();
	menuMove.setVolume(30);
	menuSelect.setVolume(30);

	while (window.isOpen() && playGame == false) {
		Event event;

		if (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyReleased) {
				switch (event.key.code) {
				case Keyboard::Up:
					this->moveUp();
					menuMove.play();
					break;
				case Keyboard::W:
					this->moveUp();
					menuMove.play();
					break;
				case Keyboard::S:
					this->moveDown();
					menuMove.play();
					break;
				case Keyboard::Down: 
					this->moveDown();
					menuMove.play();
					break;
				case Keyboard::Enter:
					menuSelect.play();
					switch (this->getUserSelection()) {
					case 0:
						playGame = true;
						break;
					case 1:
						this->drawRules(window);
						break;
					case 2:
						window.close();
						break;
					default:
						break;
					}
					break;
				case Keyboard::Num1:
					menuSelect.play();
					
					playGame = true;
					break;
				case Keyboard::Num2:
					menuSelect.play();
					this->drawRules(window);
					break;
				case Keyboard::Num3:
					menuSelect.play();
					window.close();
					break;
				case Keyboard::Escape:
					window.close();
					break;
				default:
					break;
				}
			}
			if (event.type == Event::MouseMoved) {
				Vector2f mousePosition;
				mousePosition.x = sf::Mouse::getPosition(window).x;
				mousePosition.y = sf::Mouse::getPosition(window).y;
				if (mainMenuText[0].getGlobalBounds().contains(mousePosition)) {
					if (userSelection != 0) {
						userHoversPlayGame();
						menuMove.play();
					}
				}
				else if (mainMenuText[1].getGlobalBounds().contains(mousePosition)) {
					if (userSelection != 1) {
						userHoversRules();
						menuMove.play();
					}
				}
				else if (mainMenuText[2].getGlobalBounds().contains(mousePosition)) {
					if (userSelection != 2) {
						userHoversQuit();
						menuMove.play();
					}
				}
			}
			if (event.type == Event::MouseButtonReleased) {
				Vector2f mousePosition;
				mousePosition.x = sf::Mouse::getPosition(window).x;
				mousePosition.y = sf::Mouse::getPosition(window).y;
				if (mainMenuText[0].getGlobalBounds().contains(mousePosition) && userSelection == 0) {
					playGame = true;
					menuSelect.play();
				}
				else if (mainMenuText[1].getGlobalBounds().contains(mousePosition) && userSelection == 1) {
					menuSelect.play();
					this->drawRules(window);
				}
				else if (mainMenuText[2].getGlobalBounds().contains(mousePosition) && userSelection == 2) {
					menuSelect.play();
					window.close();
				}
			}
		}
		if (window.isOpen()) {
			window.clear();
			this->drawMainMenu(window);
			window.display();
		}
	}
	background.stop();
	return(playGame);
}


/********************************************************************************************************
* Function: userHoversPlayGame()
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Changes the color of the currently selected MainMenu Text object to the normal menu text
* color, then sets userSelection to 0 and updates color of the MainMenu Text object at index 0 to Yellow.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void MainMenu::userHoversPlayGame() {
	mainMenuText[userSelection].setFillColor(Color(0, 166, 248, 255));
	userSelection = 0;
	mainMenuText[userSelection].setFillColor(Color::Yellow);
}


/********************************************************************************************************
* Function: userHoversRules()
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Changes the color of the currently selected MainMenu Text object to the normal menu text
* color, then sets userSelection to 0 and updates color of the MainMenu Text object at index 1 to Yellow.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void MainMenu::userHoversRules() {	
	mainMenuText[userSelection].setFillColor(Color(0, 166, 248, 255));
	userSelection = 1;
	mainMenuText[userSelection].setFillColor(Color::Yellow);
}


/********************************************************************************************************
* Function: userHoversQuit()
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Colin Van Dyke
* Description: Changes the color of the currently selected MainMenu Text object to the normal menu text
* color, then sets userSelection to 0 and updates color of the MainMenu Text object at index 2 to Yellow.
* Input parameters: void
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void MainMenu::userHoversQuit() {
	mainMenuText[userSelection].setFillColor(Color(0, 166, 248, 255));
	userSelection = 2;
	mainMenuText[userSelection].setFillColor(Color::Yellow);
}