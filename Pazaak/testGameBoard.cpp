#include "testGameBoard.hpp"

/********************************************************************************************************
* Function: testGetBotCardPosition
* Date Created: 4/23/2024
* Date Last Modified: 4/23/2024
* Programmer: Caitlyn Boyd
* Description: tests gameboard member function getBotCardPosition.
* Input parameters:NONE
* Returns: bool testPassed
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
bool testGameBoard::testGetBotCardPosition()
{
	bool testPassed = true;

	sf::Vector2f position = testBoard.getBotCardPosition(1);

	if (position.x != 176)
	{
		testPassed = false;
	}
	if (position.y != 125)
	{
		testPassed = false;
	}

	return testPassed;
}

/********************************************************************************************************
* Function: testGetPlayerCardPosition
* Date Created: 4/23/2024
* Date Last Modified: 4/23/2024
* Programmer: Caitlyn Boyd
* Description: tests gameboard member function getPlayerCardPosition.
* Input parameters:NONE
* Returns: bool testPassed
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
bool testGameBoard::testGetPlayerCardPosition()
{
	bool testPassed = true;

	sf::Vector2f position = testBoard.getPlayerCardPosition(1);

	if (position.x != 176)
	{
		testPassed = false;
	}
	if (position.y != 125)
	{
		testPassed = false;
	}

	return testPassed;
}

/********************************************************************************************************
* Function: testSetBotScoreOf11
* Date Created: 4/23/2024
* Date Last Modified: 4/23/2024
* Programmer: Caitlyn Boyd
* Description: tests gameboard member function setBotScore with an input value of 11.
* Input parameters:NONE
* Returns: bool passed
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
bool testGameBoard::testSetBotScoreOf11()
{
	bool passed = true;
	testBoard.setBotScore(11);

	if (testBoard.getBotScore().getString() != "11")
	{
		passed = false;
		cout << "Failure due to incorrect value" << endl;
	}
	if (testBoard.getBotScore().getPosition().x != 850 || testBoard.getBotScore().getPosition().y != 375)
	{
		passed = false;
		cout << "Failure due to incorrect position" << endl;
	}
	return passed;
}

/********************************************************************************************************
* Function: testSetPlayerScoreOf20
* Date Created: 4/23/2024
* Date Last Modified: 4/23/2024
* Programmer: Caitlyn Boyd
* Description: tests gameboard member function setPlayerScore with an input value of 20.
* Input parameters:NONE
* Returns: bool passed
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
bool testGameBoard::testSetPlayerScoreOf20()
{
	bool passed = true;
	testBoard.setPlayerScore(20);

	if (testBoard.getPlayerScore().getString() != "20")
	{
		passed = false;
		cout << "Failure due to incorrect value" << endl;
	}
	if (testBoard.getPlayerScore().getPosition().x != 835, testBoard.getPlayerScore().getPosition().y != 375)
	{
		passed = false;
		cout << "Failure due to incorrect position" << endl;
	}
	return passed;
}


/********************************************************************************************************
* Function: testConstructor
* Date Created: 4/23/2024
* Date Last Modified: 4/23/2024
* Programmer: Caitlyn Boyd
* Description: tests gameboard constructor.
* Input parameters:NONE
* Returns: bool passed
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
bool testGameBoard::testConstructor()
{
	bool passed = true;

	if (testBoard.getBackground().getPosition().x != 0 || testBoard.getBackground().getPosition().y)
	{
		passed = false;
		cout << "Failure due to incorrect background position" << endl;
	}
	if (testBoard.getScoreCardPosition().x != 640 || testBoard.getScoreCardPosition().y != 325)
	{
		passed = false;
		cout << "Failure due to incorrect scoreCard position" << endl;
	}

	return passed;
}

