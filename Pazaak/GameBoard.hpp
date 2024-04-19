#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using sf::RectangleShape;
using sf::CircleShape;
using sf::Vector2f;
using sf::RenderWindow;
using sf::Color;
using sf::Font;
using sf::Text;

class GameBoard
{
public:
	GameBoard();

	vector<RectangleShape> getPlayerHand();
	void initCards();
	void initIndicators();

	void display(RenderWindow& window);

	void setPlayerIndicator(int score);
	void setBotIndicator(int score);
	void setTurnIndicator(int player);
	Vector2f getBotCardPosition(int card);
	Vector2f getPlayerCardPosition(int card);
	
	
private:
	vector<RectangleShape> playerHand;
	vector<RectangleShape> botHand;
	vector<RectangleShape> playerSide;
	vector<RectangleShape> botSide;
	RectangleShape background;
	vector<CircleShape> playerIndicator;
	vector<CircleShape> botIndicator;
	vector<CircleShape> turnIndicator;
	Font fontType;
	Text turnIndicatorText;
	Text playerText;
	Text botText;
};

/********************************************************************************************************
* Function: GameBoard constructor
* Date Created: 4/17/2024
* Date Last Modified: 4/18/2024
* Programmer: Caitlyn Boyd, Colin Van Dyke
* Description: Initializes all the shapes and text on the gameboard.				
* Input parameters:NONE
* Returns: void	
* Preconditions: None
* Postconditions: None
********************************************************************************************************/

GameBoard::GameBoard()
{
	// Initializes background rectangleShape
	Color lightGrey(128, 128, 128);
	background.setSize({ 1600, 900 });
	background.setFillColor(lightGrey);
	background.setPosition(0, 0);

	if (!fontType.loadFromFile("Old_R.ttf")) {
		cout << "Failure to load font." << endl;
	}
	playerText.setFont(fontType);
	playerText.setCharacterSize(40);
	playerText.setStyle(Text::Bold);
	playerText.setFillColor(Color::Black);
	playerText.setPosition({ 225.f, 60.f });
	playerText.setString("Player");

	botText.setFont(fontType);
	botText.setCharacterSize(40);
	botText.setStyle(Text::Bold);
	botText.setFillColor(Color::Black);
	botText.setPosition({ 225.f + 840, 60.f }); // ignore weird math, it just helped keep positions consistent
	botText.setString("Opponent");

	turnIndicatorText.setFont(fontType);
	turnIndicatorText.setCharacterSize(20);
	turnIndicatorText.setStyle(Text::Bold);
	turnIndicatorText.setFillColor(Color::Black);
	turnIndicatorText.setPosition({ 735, 150 });
	turnIndicatorText.setString("Turn");
	
	// initializes cards
	initCards();

	// initializes circle indicators (turn and score)
	initIndicators();
	
	
}

/********************************************************************************************************
* Function: initCards
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Caitlyn Boyd
* Description: Initializes all the card shapes for the gameboard and populates the appropriate vectors.
* Input parameters:NONE
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/

void GameBoard::initCards()
{
	Color darkGrey(32, 32, 32);
	RectangleShape newCard({ 100, 125 });
	newCard.setFillColor(darkGrey);
	newCard.setOutlineColor(Color::Black);
	newCard.setOutlineThickness(3.f);

	int factora = 1, factorb = 1, factorc = 1, factorD = 1;
	for (int i = 0; i < 9; i++)
	{
		playerHand.push_back(newCard);
		botHand.push_back(newCard);
		if (i < 3)
		{
			playerHand[i].setPosition({ 175.f + factora, 125.f });
			factora += 125;
			botHand[i].setPosition({ 175.f + factora + 750, 125.f });
		}
		else if (i < 6)
		{
			playerHand[i].setPosition({ 175.f + factorb, 275.f });
			factorb += 125;
			botHand[i].setPosition({ 175.f + factorb + 750, 275.f });
		}
		else
		{
			playerHand[i].setPosition({ 175.f + factorc, 425.f });
			factorc += 125;
			botHand[i].setPosition({ 175.f + factorc + 750, 425.f });
		}
		
	}
	
	for (int i = 0; i < 4; i++)
	{
		playerSide.push_back(newCard);
		botSide.push_back(newCard);
		playerSide[i].setPosition({ 125.f + factorD, 650 });
		botSide[i].setPosition({ 125.f + factorD + 850, 650 });
		factorD += 125;
	}



}

/********************************************************************************************************
* Function: getPlayerHand
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Caitlyn Boyd
* Description: Initializes all the shapes on the gameboard.
* Input parameters:NONE
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/

vector<RectangleShape> GameBoard::getPlayerHand()
{
	return playerHand;
}

/********************************************************************************************************
* Function: display
* Date Created: 4/17/2024
* Date Last Modified: 4/18/2024
* Programmer: Caitlyn Boyd, Colin Van Dyke
* Description: draws all the gameboard elements to a RenderWindow.
* Input parameters: RenderWindow& window
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void GameBoard::display(RenderWindow& window)
{
	window.draw(background);

	for (int i = 0; i < 9; i++)
	{
		window.draw(playerHand[i]);
		window.draw(botHand[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		window.draw(playerSide[i]);
		window.draw(botSide[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		window.draw(botIndicator[i]);
		window.draw(playerIndicator[i]);
	}

	window.draw(playerText);
	window.draw(botText);
	window.draw(turnIndicatorText);
	window.draw(turnIndicator[0]);
	window.draw(turnIndicator[1]);
}

/********************************************************************************************************
* Function: initIndicators
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Caitlyn Boyd
* Description: Initializes all three indicators including required shapes.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void GameBoard::initIndicators()
{
	// Score indicators
	Color mediumGrey(64, 64, 64);
	CircleShape circle(15.f);
	circle.setFillColor(mediumGrey);
	circle.setOutlineColor(Color::Black);
	circle.setOutlineThickness(3.f);
	int adjustment = 0;

	for (int i = 0; i < 3; i++)
	{
		playerIndicator.push_back(circle);
		botIndicator.push_back(circle);
		playerIndicator[i].setPosition(125, 150 + adjustment); // ignore weird math, it just helped keep positions consistent
		botIndicator[i].setPosition(125 + 1300, 150 + adjustment);

		adjustment += 30;
	}

	// turn indicator
	
	circle.setPosition({ 450 + 225 + 10, 150 }); // ignore weird math, it just helped keep positions consistent
	turnIndicator.push_back(circle);
	circle.setPosition({ 550 + 285 + 10, 150 });
	turnIndicator.push_back(circle);
}

/********************************************************************************************************
* Function: setPlayerIndicator
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Caitlyn Boyd
* Description: A mutator method for the player score indicator on the left hand side of the board. Allows for the score to be changed.
* Input parameters:NONE
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void GameBoard::setPlayerIndicator(int score)
{
	int limit = -1;
	if (score == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			playerIndicator[i].setFillColor(Color(64, 64, 64));
		}
	}
	if (score > 3)
	{
		limit = 3;
	}
	else
	{
		limit = score;
	}

	for (int i = 0; i < limit; i++)
	{
		playerIndicator[i].setFillColor(Color::Red);
	}
}

/********************************************************************************************************
* Function: setBotIndicator
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Caitlyn Boyd
* Description: A mutator method for the bot score indicator on the right hand side of the board. Allows for the score to be changed.
* Input parameters: int score
* Returns: void
* Preconditions: None
* Postconditions: None
********************************************************************************************************/
void GameBoard::setBotIndicator(int score)
{
	int limit = -1;
	if (score == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			botIndicator[i].setFillColor(Color(64, 64, 64));
		}
	}
	if (score > 3)
	{
		limit = 3;
	}
	else
	{
		limit = score;
	}
	for (int i = 0; i < limit; i++)
	{
		botIndicator[i].setFillColor(Color::Red);
	}
}

/********************************************************************************************************
* Function: setTurnIndicator
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Caitlyn Boyd, Colin Van Dyke
* Description: A mutator method for the turn indicator in the center of the board. Input 1 (player) or 2 (bot) to change the indicator.
* Input parameters: int player
* Returns: void
* Preconditions: 3 > player > 0
* Postconditions: None
********************************************************************************************************/
void GameBoard::setTurnIndicator(int player)
{
	switch (player)
	{
	case 1:
		turnIndicator[0].setFillColor(Color::Red);
		turnIndicator[1].setFillColor(Color(64, 64, 64));
		break;
	case 2:
		turnIndicator[1].setFillColor(Color::Red);
		turnIndicator[0].setFillColor(Color(64, 64, 64));
		break;
	default:
		break;
	}	
}

/********************************************************************************************************
* Function: getBotCardPosition
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Caitlyn Boyd, Colin Van Dyke
* Description: Accessor method for each card on the right had side of the board based on their position in each vector.
* Input parameters: int card
* Returns: Vector2f result - position of the card selected.
* Preconditions: -1 < card < 13
* Postconditions: None
********************************************************************************************************/
Vector2f GameBoard::getBotCardPosition(int card)
{
	Vector2f result;
	if (card > -1 && card < 13)
	{
		if (card < 9)
		{
			result = botHand[card].getPosition();
		}
		else
		{
			result = botSide[card - 9].getPosition();
		}
	}

	return result;
}

/********************************************************************************************************
* Function: getPlayerCardPosition
* Date Created: 4/17/2024
* Date Last Modified: 4/17/2024
* Programmer: Caitlyn Boyd, Colin Van Dyke
* Description: An accessor method for the cards on the left hand side of the gameboard according to their position in the vectors.
* Input parameters: int card
* Returns: Vector2f result - position of the card selected.
* Preconditions: -1 < card < 13
* Postconditions: None
********************************************************************************************************/
Vector2f GameBoard::getPlayerCardPosition(int card)
{
	Vector2f result;
	if (card > -1 && card < 13)
	{
		if (card < 9)
		{
			result = playerHand[card].getPosition();
		}
		else
		{
			result = playerSide[card - 9].getPosition();
		}
	}

	return result;
}