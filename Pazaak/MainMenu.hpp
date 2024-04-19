#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Mouse.hpp>

#define NUMBER_OF_OPTIONS 3

using sf::RenderWindow;
using sf::Font;
using sf::Text;
using sf::Color;
using sf::Event;
using sf::VideoMode;
using sf::Keyboard;
using sf::RectangleShape;
using sf::Vector2f;
using sf::Texture;
using std::cout;
using std::endl;

// Design for MainMenu class largely borrowed from a YouTube tutorial.
// Made a lot of modifications because some of the things this person wrote either seemed pointless
// or needlessly complicated or I just didn't understand what they were doing so made up my own solution.
// Tutorial can be found here: https://www.youtube.com/watch?v=bOG8667yePY

class MainMenu
{
public:
	// CONSTRUCTOR
	MainMenu();

	// DESTRUCTOR
	~MainMenu();

	// ACCESSOR
	int getUserSelection();

	// METHODS
	bool runMainMenu(RenderWindow& window);
	void drawMainMenu(RenderWindow& window);
	void moveUp();
	void moveDown();
	void drawRules(RenderWindow& window) const;
	void userHoversPlayGame();
	void userHoversRules();
	void userHoversQuit();

private:
	int userSelection;
	Font fontType;
	Text* mainMenuText;
	RectangleShape backgroundImage;
	Texture backgroundTexture;
};

