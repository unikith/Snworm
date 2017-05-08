#pragma once
#include "Settings.h"
#include <SFML\Graphics.hpp>

class GameSettings :
	public Settings
{
public:
	GameSettings(const char * LoadFile);
	~GameSettings();

	void load();
	void save();

	sf::Color & getP1Color() { return mP1SnakeColor; }
	float getNodeRadius() const{ return mNodeRadius; }
	float getSpeed() const { return mSpeed; }
	float getTurnSpeed() const { return mTurnSpeed; }
	sf::Keyboard::Key & getP1Left() { return mP1Left; }
	sf::Keyboard::Key & getP1Right() { return mP1Right; }
	sf::Color & getPickupColor() { return mConsumableColor; }
	float getPickupRadius() const { return mConsumableRadius; }

	sf::Color & getP2Color() { return mP2SnakeColor; }
	sf::Keyboard::Key & getP2Left() { return mP2Left; }
	sf::Keyboard::Key & getP2Right() { return mP2Right; }
private:
	sf::Color mP1SnakeColor;
	float mNodeRadius;
	float mSpeed;
	float mTurnSpeed;
	sf::Keyboard::Key mP1Left;
	sf::Keyboard::Key mP1Right;
	sf::Color mConsumableColor;
	float mConsumableRadius;

	sf::Color mP2SnakeColor;
	sf::Keyboard::Key mP2Left;
	sf::Keyboard::Key mP2Right;

};

