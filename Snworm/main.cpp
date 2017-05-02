/*
*	Programmer : James Nelson
*	Description : a two-player snake game with tank controls and serveral different modes
*				of play. Uses SFML
*	Modes : two-player vs, two-player coop, single player 
*			**coop and single player have leader boards**
*/
#include <SFML\Graphics.hpp>

#include "Snake.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Snworm");
	Snake p1(sf::Color::Red, 5, sf::Vector2f(100, 100), .1);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		p1.move();

		window.clear();
		p1.drawInWindow(window);
		window.display();
	}

	return 0;
}