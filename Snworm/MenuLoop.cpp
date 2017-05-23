#include "MenuLoop.h"



MenuLoop::MenuLoop()
{
}


MenuLoop::~MenuLoop()
{
}

t_GameMode MenuLoop::runLoop(sf::RenderWindow & window)
{
	t_GameMode menuSelection = EXIT;
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
	}

	return menuSelection;
}
