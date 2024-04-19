#pragma once
#include <SFML/Graphics.hpp>
#include "SwitchCard.hpp"
#include "MainCard.hpp"
#include <iostream>
#include <vector>
#define MAIN_HAND_SIZE 9
#define SIDE_HAND_SIZE 4

using sf::RenderWindow;

class Match
{
public:
	// CONSTRUCTOR
	Match();

	// DESTRUCTOR
	~Match();

	// METHOD
	void initializeSideDecks();
	unsigned int playMatch(RenderWindow& window);
	void displayMatch(RenderWindow& window);

private:
	// Board* gameBoard;
	Card** playerMainCards;
	Card** playerSideCards;
	Card** computerMainCards;
	Card** computerSideCards;
	unsigned int playerCardsDealt;
	unsigned int computerCardsDealt;
};

