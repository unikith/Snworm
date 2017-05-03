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
	sf::RenderWindow window(sf::VideoMode(1200, 600), "Snworm");
	Snake p1(sf::Vector2f(100, 100), sf::Color::Red, 5,  .15, .005,
		sf::Keyboard::Right, sf::Keyboard::Left);
	//Snake p2(sf::Vector2f(900, 500), sf::Color::Yellow, 5, .05, .005,
	//	sf::Keyboard::A, sf::Keyboard::D);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			p1.runEvent(event);
			//p2.runEvent(event);
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		p1.move();
		//p2.move();

		window.clear();
		p1.drawInWindow(window);
		//p2.drawInWindow(window);
		window.display();
	}

	return 0;
}