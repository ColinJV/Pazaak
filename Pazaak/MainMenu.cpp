#include "MainMenu.hpp"

/********************************************************************************************************
* Function: MainMenu constructor																		*
* Date Created: 4/14/2024																				*
* Date Last Modified: 4/14/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Constructs a MainMenu object.															*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
MainMenu::MainMenu() {
	if (!fontType.loadFromFile("Old_R.ttf")) {
		cout << "Font not found in project path." << endl;
	}
	
	backgroundImage.setSize(Vector2f(1600, 900));
	backgroundImage.setPosition(0, 0);
	backgroundTexture.loadFromFile("splashMenu.png");
	backgroundImage.setTexture(&backgroundTexture);

	// Play
	mainMenu[0].setFont(fontType);
	mainMenu[0].setFillColor(Color::Yellow);
	mainMenu[0].setString("1. Play Game");
	mainMenu[0].setCharacterSize(20);
	mainMenu[0].setPosition(800, 425);

	// Rules
	mainMenu[1].setFont(fontType);
	mainMenu[1].setFillColor(Color(0, 166, 248, 255));
	mainMenu[1].setString("2. Rules");
	mainMenu[1].setCharacterSize(20);
	mainMenu[1].setPosition(835, 490);

	// Quit
	mainMenu[2].setFont(fontType);
	mainMenu[2].setFillColor(Color(0, 166, 248, 255));
	mainMenu[2].setString("3. Quit");
	mainMenu[2].setCharacterSize(20);
	mainMenu[2].setPosition(850, 560);

	userSelection = 0;
}


/********************************************************************************************************
* Function: MainMenu destructor																			*
* Date Created: 4/14/2024																				*
* Date Last Modified: 4/14/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Destroys a MainMenu object.																*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
MainMenu::~MainMenu() {

}


/********************************************************************************************************
* Function: drawMainMenu()																				*
* Date Created: 4/14/2024																				*
* Date Last Modified: 4/14/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Draws the MainMenu text on the input RenderWindow										*
* Input parameters: RenderWindow& window, a reference to a RenderWindow that is the game's graphics		*
* window.																								*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void MainMenu::drawMainMenu(RenderWindow& window) {
	window.draw(backgroundImage);

	for (int index = 0; index < 3; ++index) {
		window.draw(mainMenu[index]);
	}
}


/********************************************************************************************************
* Function: moveUp()																					*
* Date Created: 4/14/2024																				*
* Date Last Modified: 4/14/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Modifies which option on the main menu is highlighted and decrements the userSelection	*
* member variable of MainMenu. Checks if userSelection is out of bounds and corrects it if it is.		*
* Input parameters: void																				*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void MainMenu::moveUp() {
	if (userSelection >= 0) {
		mainMenu[userSelection--].setFillColor(Color(0, 166, 248, 255));
		if (userSelection == -1) {
			userSelection = 2;
		}
		mainMenu[userSelection].setFillColor(Color::Yellow);
	}
}


/********************************************************************************************************
* Function: moveUp()																					*
* Date Created: 4/14/2024																				*
* Date Last Modified: 4/14/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Modifies which option on the main menu is highlighted and increments the userSelection	*
* member variable of MainMenu. Checks if userSelection is out of bounds and corrects it if it is.		*
* Input parameters: int cardValue																		*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
void MainMenu::moveDown() {
	if (userSelection <= NUMBER_OF_OPTIONS) {
		mainMenu[userSelection++].setFillColor(Color(0, 166, 248, 255));
		if (userSelection == NUMBER_OF_OPTIONS) {
			userSelection = 0;
		}
		mainMenu[userSelection].setFillColor(Color::Yellow);
	}
}


/********************************************************************************************************
* Function: drawRules()																					*
* Date Created: 4/14/2024																				*
* Date Last Modified: 4/14/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Creates 3 sf::Text objects; a rules header, rules text, and controls header. Applies 	*
* settings for the text then draws it and displays it to the window, reading user inputs until either	*
* the user elects to return to the Main Menu or the window closes.										*
* Input parameters: RenderWindow& window, a reference to the RenderWindow object that is the game		*
* window.																								*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
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
		"Upon playing a card from the Side Deck, or choosing not to, the player may end their turn or stand.\n"
		"Standing will end all your action for the current set.\n"
		"The objective is to reach a total score of 20 without exceeding 20, a.k.a. busting.\n"
		"If a player busts, their opponent wins the set automatically.\n"
		"If a player reaches 20 points, they stand automatically.\n"
		"If a player has 9 cards on their board and has not busted, they win the set automatically.\n"
		"The first player to win three sets wins the match.\n\n\n\n"
		"Enter to End Turn. Backspace to Stand and end your action for this set.\n"
		"Num1 through Num4 to use your Side Deck cards 1-4 respectively.\n"
		"Shift+Num3 and Shift+Num4 will swap the value of your third and fourth\n"
		"Side Deck cards between positive and negative.\n\n\n"
		"Press Enter/Spacebar to return to the Main Menu.");
	rules.setPosition(70, 100);
	rules.setCharacterSize(15);

	controlsHeader.setFont(fontType);
	controlsHeader.setFillColor(Color::Yellow);
	controlsHeader.setString("Controls");
	controlsHeader.setCharacterSize(30);
	controlsHeader.setPosition(50, 490);

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
* Function: drawRules()																					*
* Date Created: 4/14/2024																				*
* Date Last Modified: 4/14/2024																			*
* Programmer: Colin Van Dyke																			*
* Description: Creates two sf::Text objects, one for a header and one for the rule text. Sets settings	*
* for the text then draws it and displays it to the window, reading user inputs until either the user	*
* elects to return to the Main Menu or the window closes.												*
* Input parameters: RenderWindow& window, a reference to the RenderWindow object that is the game		*
* window.																								*
* Returns: void																							*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
int MainMenu::getUserSelection() {
	return(userSelection);
}


/********************************************************************************************************
* Function: runMainMenu()																				*
* Date Created: 4/14/2024																				*
* Date Last Modified: 4/16/2024																			*
* Programmer: Colin Van Dyke, Nick McBrayer																			*
* Description: Main logic function for MainMenu object. Draws and displays the MainMenu to the window	*
* and conducts event polling. Highlights various menu options based on userSelection value. Loops until *
* the window closes or until the player chooses to play the game, at which point a boolean flag is set	*
* and returned to the calling function.																	*
* Input parameters: RenderWindow& window, a reference to the RenderWindow object that is the game		*
* window.																								*
* Returns: bool playGame, a boolean flag that controls loop repetition and, when returned to the calling*
* function, will initiate the primary gameplay logic.													*
* Preconditions: None																					*
* Postconditions: None																					*
********************************************************************************************************/
bool MainMenu::runMainMenu(RenderWindow& window) {
	bool playGame = false;
	sf::Music music;
	if (!music.openFromFile("audio/mus_theme_cult.wav")) {
		cout << "Main Theme Error!" << endl;
	}
	music.setVolume(20);
	music.setLoop(true);
	music.play();
	sf::SoundBuffer buffer1, buffer2;
	if (!buffer1.loadFromFile("audio/kotor_menu_sfx2.wav")) {
		cout << "Sound1 Error!" << endl;
	}
	if (!buffer2.loadFromFile("audio/kotor_menu_sfx.wav")) {
		cout << "Sound2 Error!" << endl;
	}
	sf::Sound sound1, sound2;
	sound1.setBuffer(buffer1);
	sound1.setVolume(20);
	sound2.setBuffer(buffer2);
	sound2.setVolume(20);
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
					sound1.play();
					break;
				case Keyboard::Down:
					this->moveDown();
					sound1.play();
					break;
				case Keyboard::Enter:
					sound2.play();
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
					playGame = true;
					break;
				case Keyboard::Num2:
					this->drawRules(window);
					break;
				case Keyboard::Num3:
					window.close();
					break;
				case Keyboard::Escape:
					window.close();
					break;
				}
			}

			window.clear();

			this->drawMainMenu(window);

			window.display();
		}
	}
	return(playGame);
}