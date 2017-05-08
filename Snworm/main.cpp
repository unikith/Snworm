/*
*	Programmer : James Nelson
*	Description : a two-player snake game with tank controls and serveral different modes
*				of play. Uses SFML
*	Modes : two-player vs, two-player coop, single player 
*			**coop and single player have leader boards**
*/
#include "GameLoop.h"

int main(void)
{
	WindowSettings wsettings("WindowSettings.txt");
	sf::RenderWindow window(sf::VideoMode(wsettings.getWidth(), wsettings.getHeight()), "Snworm");
	window.setFramerateLimit(wsettings.getFrameRate());
	window.setMouseCursorVisible(false);

	GameLoop mainLoop("GameSettings.txt");
	mainLoop.runLoop(SinglePlayer, window);

	//Snake p1(sf::Vector2f(100, 100), sf::Color::Red, 7.5, 7.5, .1,
	//	sf::Keyboard::Right, sf::Keyboard::Left);
	////Snake p2(sf::Vector2f(900, 500), sf::Color::Yellow, 5, .05, .005,
	////	sf::Keyboard::A, sf::Keyboard::D);
	//Consumable *pickUps = nullptr;

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		p1.runEvent(event);
	//		//p2.runEvent(event);
	//		if (event.type == sf::Event::Closed)
	//		{
	//			window.close();
	//		}
	//		
	//	}
	//	if (pickUps == nullptr)
	//	{
	//		pickUps = new Consumable(window, sf::Color::Cyan, 12);
	//	}
	//	p1.move();
	//	//p2.move();
	//	if (pickUps != nullptr && Collider::checkCollision(*pickUps, p1.getHead()))
	//	{
	//		delete pickUps;
	//		pickUps = nullptr;
	//		p1.spawn();
	//	}
	//	window.clear();
	//	p1.drawInWindow(window);
	//	if (pickUps != nullptr)
	//	{
	//		window.draw(*pickUps);
	//	}
	//	//p2.drawInWindow(window);
	//	window.display();
	//}

	window.close();
	return 0;
}