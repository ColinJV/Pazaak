#pragma once

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
	void initScoreCard();

	void display(RenderWindow& window);

	void setPlayerIndicator(int score);
	void setBotIndicator(int score);
	void setTurnIndicator(int player);
	void setPlayerScore(int score);
	void setBotScore(int score);
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
	RectangleShape scoreCard;
	Text botScore;
	Text playerScore;
	Text scoreCardLabels;
	sf::Texture scoreCard_texture;
	sf::Texture background_texture;
	sf::Texture scoreIndicator_texture;
	sf::Texture cardSkin;
};