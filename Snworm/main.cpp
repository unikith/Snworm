/*
*	Programmer : James Nelson
*	Description : a two-player snake game with tank controls and serveral different modes
*				of play. Uses SFML
*	Modes : two-player vs, two-player coop, single player 
*			**coop and single player have leader boards**
*/
#include "MenuLoop.h"

int main(void)
{
	WindowSettings wsettings("WindowSettings.txt");
	sf::RenderWindow window(sf::VideoMode(wsettings.getWidth(), wsettings.getHeight()), "Snworm");
	window.setFramerateLimit(wsettings.getFrameRate());
	window.setMouseCursorVisible(false);
	GameLoop mainLoop("GameSettings.txt");
	while (window.isOpen())
	{
		mainLoop.runLoop(SinglePlayer, window);
	}
	window.close();
	return 0;
}