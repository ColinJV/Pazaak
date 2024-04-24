/*
* Programmer: Colin Van Dyke (Lab Section 3)
* Programmer: Joshua Allard (Lab Section 3)
* Programmer: Nick McBrayer (Lab Section 3)
* Programmer: Caitlyn Boyd (Lab Section 6)
* Project Name: PA9, Pazaak Rules
* Class: Washington State University CS122 Spring 2024, Prof. Andy O'Fallon
* Description: This program implements a game of Pazaak, a card game originating
* in the Star Wars: Knights of the Old Republic series. The rules and controls can
* be viewed in the Rules Menu, accessed via the Main Menu. Inheritance and polymorphism
* are implemented according to the following structure:
*       1) Card is an abstract class with a pure virtual function called drawCardInWindow().
*       2) MainCard inherits from Card
*       3) SideCard inherits from Card
*       4) SwitchCard inherits from SideCard
*       5) Each derived class of Card overrides drawCardInWindow()
* Preliminary unimplemented networking features exist in Network.hpp/.cpp and in
* DataHandler.hpp/.cpp. These classes are incomplete and commented out, and the project will
* not build if they are not commented out. This implementation uses a simple AI for the opponent
* rather than a networked player.
*/

#include "Game.hpp"

int main()
{
	srand((unsigned int)time(NULL));
	Game newGame;
	newGame.runGame();
	return(0);
}
