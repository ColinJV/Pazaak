#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.hpp"
int main()
{
    RenderWindow window(VideoMode(1600, 900), "Menutest", sf::Style::Default);
    window.setFramerateLimit(60);
    MainMenu menu;
    bool junk = false;
    junk = menu.runMainMenu(window);
    return 0;
}