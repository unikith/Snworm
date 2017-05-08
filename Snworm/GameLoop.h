#pragma once
#include "Consumable.h"
#include "Collider.h"
#include "GameSettings.h"
#include "Snake.h"
#include "WindowSettings.h"


typedef enum gameMode
{
	SinglePlayer = 0, TwoPlayerCoop, TwoPlayerVS 
}t_GameMode;

class GameLoop
{
public:
	GameLoop(const char * LoadFile);
	~GameLoop();
	int runLoop(t_GameMode mode, sf::RenderWindow & window);

private:
	GameSettings mSettings;
	
	int singlePlayerLoop(sf::RenderWindow & window);
	int twoPlayerCoopLoop(sf::RenderWindow & window);

	void initializeFont(sf::Text & text, sf::Font & font);
};

