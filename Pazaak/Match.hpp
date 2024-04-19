#pragma once
#include <SFML/Graphics.hpp>
#include "SwitchCard.hpp"
#include "MainCard.hpp"
#include "GameBoard.hpp"

#define MAIN_HAND_SIZE 9
#define SIDE_HAND_SIZE 4

using sf::RenderWindow;
using sf::Event;
using sf::Keyboard;

class Match
{
public:
	// CONSTRUCTOR
	Match();

	// DESTRUCTOR
	~Match();

	// METHOD
	void initializeSideDecks();
	int playMatch(RenderWindow& window);
	void displayMatch(RenderWindow& window);
	void drawAllCardsOnBoard(RenderWindow& window);
	void dealMainCard(Card*& newCardSlot, int& player);
	void playerDecision(RenderWindow& window, int& player, bool& playerStands);
	void playSideCard(Card*& sideCard, int& player);
	void playerWinsASet();
	void computerWinsASet();
	void updatePlayerScore();


private:
	GameBoard* gameBoard;
	Card** playerMainCards;
	Card** playerSideCards;
	Card** computerMainCards;
	Card** computerSideCards;
	int mPlayerCardsDealt;
	int mComputerCardsDealt;
	int mPlayerSetWins;
	int mComputerSetWins;
	int mPlayerScore;
	int mComputerScore;
};

