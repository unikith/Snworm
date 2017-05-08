#include "GameLoop.h"

GameLoop::GameLoop(const char * LoadFile) : mSettings(LoadFile){/*Empty*/}


GameLoop::~GameLoop(){/*Empty*/}

int GameLoop::runLoop(t_GameMode mode, sf::RenderWindow & window)
{
	int score = 0;
	switch (mode)
	{
	case SinglePlayer:
		score = singlePlayerLoop(window);
		break;
	case TwoPlayerCoop:
		score = twoPlayerCoopLoop(window);
		break;
	case TwoPlayerVS:
		break;
	default:
		break;
	}
	return score;
}

int GameLoop::singlePlayerLoop(sf::RenderWindow & window)
{
	Snake p1(sf::Vector2f(100, 100), mSettings.getP1Color(), mSettings.getNodeRadius(), 
		mSettings.getSpeed(), mSettings.getTurnSpeed(),
		sf::Keyboard::Right, sf::Keyboard::Left);
	
	Consumable *pickUps = nullptr;
	bool gameOver = false;
	int score = 0;

	sf::Text scoreText;
	sf::Font font;
	initializeFont(scoreText, font);

	while (window.isOpen() && !gameOver)
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			p1.runEvent(event);
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}

		p1.move();

		if (pickUps == nullptr)
		{
			pickUps = new Consumable(window, mSettings.getPickupColor(), 
									mSettings.getPickupRadius());
		}
		else if (Collider::checkCollision(*pickUps, p1.getHead()))
		{
			delete pickUps;
			pickUps = nullptr;
			p1.spawn();
			++score;
		}
		scoreText.setString(std::to_string(score));
		window.clear();
		p1.drawInWindow(window);
		if (pickUps != nullptr)
		{
			window.draw(*pickUps);
		}
		window.draw(scoreText);
		window.display();
	}

	return score;
}

int GameLoop::twoPlayerCoopLoop(sf::RenderWindow & window)
{
	Snake p1(sf::Vector2f(100, 100), mSettings.getP1Color(), mSettings.getNodeRadius(),
		mSettings.getSpeed(), mSettings.getTurnSpeed(),
		sf::Keyboard::Right, sf::Keyboard::Left);

	Snake p2(sf::Vector2f(900, 500), mSettings.getP2Color(), mSettings.getNodeRadius(), 
		mSettings.getSpeed(), mSettings.getTurnSpeed(),
		sf::Keyboard::A, sf::Keyboard::D);
	Consumable *pickUps = nullptr;
	bool gameOver = false;
	int score = 0;
	sf::Text scoreText;
	sf::Font font;
	initializeFont(scoreText, font);

	while (window.isOpen() && !gameOver)
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			p1.runEvent(event);
			p2.runEvent(event);
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}

		p1.move();
		p2.move();

		if (pickUps == nullptr)
		{
			pickUps = new Consumable(window, mSettings.getPickupColor(),
				mSettings.getPickupRadius());
		}
		else if (Collider::checkCollision(*pickUps, p1.getHead()))
		{
			delete pickUps;
			pickUps = nullptr;
			p1.spawn();
			++score;
		}
		else if (Collider::checkCollision(*pickUps, p2.getHead()))
		{
			delete pickUps;
			pickUps = nullptr;
			p2.spawn();
			++score;
		}
		window.clear();
		p1.drawInWindow(window);
		p2.drawInWindow(window);
		if (pickUps != nullptr)
		{
			window.draw(*pickUps);
		}
		window.draw(scoreText);
		window.display();
	}

	return score;
}

void GameLoop::initializeFont(sf::Text & text, sf::Font & font)
{
	font.loadFromFile("zombie.ttf"); //Grabs font
	text.setFont(font);
	text.setCharacterSize(30);
	text.setColor(sf::Color::Red);
	text.setPosition(10, 0);
}
