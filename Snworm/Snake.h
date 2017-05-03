#pragma once
#include <vector>

#include "SnakeHead.h"
#include "SnakeTail.h"

using std::vector;

class Snake
{
public:
	Snake(sf::Vector2f spawnPosition,sf::Color snakeColor = sf::Color::White,
		float nodeRadius = 5,  float speed = .1, float turnSpeed =  .05, 
		sf::Keyboard::Key right = sf::Keyboard::Right,
		sf::Keyboard::Key left = sf::Keyboard::Left);
	~Snake();

	void drawInWindow(sf::RenderWindow& window);
	void move();
	bool runEvent(const sf::Event & event);
private:
	vector<SnakeNode *> mSnakeBody;
	sf::Color mColor;
	float mNodeRadiuses;
	float mSpeed;
	float mTurnSpeed;
	sf::Keyboard::Key mLeftKey;
	sf::Keyboard::Key mRightKey;
	bool mHoldLeft;
	bool mHoldRight;
	int mRotaionDirection;

	bool keyPress(const sf::Event event);
	bool keyRelease(const sf::Event event);

	void startLeft();
	void startRight();
	void stopLeft();
	void stopRight();
};

