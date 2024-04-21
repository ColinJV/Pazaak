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
using sf::Clock;

class Match
{
public:
	// CONSTRUCTOR
	Match();

	// DESTRUCTOR
	~Match();

	// PUBLIC METHOD
	int playMatch(RenderWindow& window);

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
	Clock gameClock;

	// PRIVATE METHODS
	void initializeSideDecks();
	void displayMatch(RenderWindow& window);
	void drawAllCardsOnBoard(RenderWindow& window);
	void dealMainCard(Card*& newCardSlot, int& player);
	void playerDecision(RenderWindow& window, int& player, bool& playerStands, bool& computerStands);
	void computerDecision(RenderWindow& window, int& player, bool& computerStands, bool& playerStands);
	void playSideCard(Card*& sideCard, const int& player);
	void playerWinsASet();
	void computerWinsASet();
	bool playerHasSideCards();
	bool computerHasSideCards();
	void computerChooseToPlaySideCards(bool& sideCardPlayed);
	void resetSet();
	int determineWinner();
	void incrementWins(int& winner);
	bool matchWinnerExists();
	void displaySetWinMessage(int& setWinner, RenderWindow& window);
	void displayMatchWinMessage(int& setWinner, RenderWindow& window);
};

