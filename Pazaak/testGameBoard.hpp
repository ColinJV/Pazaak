#pragma once
#include "GameBoard.hpp"

class testGameBoard
{
public:
	bool testGetBotCardPosition();
	bool testGetPlayerCardPosition();
	bool testSetPlayerScoreOf20();
	bool testSetBotScoreOf11();
	bool testConstructor();

private:
	GameBoard testBoard;
};
