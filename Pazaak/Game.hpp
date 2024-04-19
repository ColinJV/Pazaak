#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"

#define PLAYER_WINS 1
#define COMPUTER_WINS 2

using sf::RenderWindow;
using sf::VideoMode;
using sf::RectangleShape;

class Game
{
public:
	// CONSTRUCTOR
	Game();

	// DESTRUCTOR
	~Game();

	// METHODS
	void runGame();
	void playerVictory();
	void computerVictory();

private:
	RenderWindow mGameWindow;
	unsigned int mPlayerWinCount;
	unsigned int mComputerWinCount;
};

