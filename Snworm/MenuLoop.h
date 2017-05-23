#pragma once
#include "GameLoop.h"

class MenuLoop
{
public:
	MenuLoop(); 
	~MenuLoop();
	t_GameMode runLoop(sf::RenderWindow  & window);
};

