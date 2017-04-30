/*
*	Programmer : James Nelson
*	Description : a two-player snake game with tank controls and serverl different modes of
*		play. Uses SFML
*	Modes : two-player vs, two-player coop, single player 
*			**coop and single player have leader boards**
*/
#include <SFML\Graphics.hpp>

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Snworm");

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
		window.clear();
		window.display();
	}

	return 0;
}