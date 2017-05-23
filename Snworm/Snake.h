#pragma once
#include <vector>

#include "SnakeHead.h"

using std::vector;

class Snake
{
	friend class SnakeTail;
public:
	Snake(sf::RenderWindow & window, sf::Color snakeColor = sf::Color::White,
		float nodeRadius = 5,  float speed = .1, float turnSpeed =  .05, 
		sf::Keyboard::Key right = sf::Keyboard::Right,
		sf::Keyboard::Key left = sf::Keyboard::Left);
	~Snake();

	void drawInWindow(sf::RenderWindow& window);
	void move();
	bool runEvent(const sf::Event & event);
	void spawn();
	SnakeNode &getHead()const { return *mSnakeBody[0]; }
	SnakeNode &getNodeI(int i) { return *mSnakeBody[i]; } 
	int getSize() { return mSize; }

private:
	vector<SnakeNode *> mSnakeBody;
	sf::Color mColor;
	float mNodeRadiuses;
	float mSpeed;
	float mTurnSpeed;
	sf::Keyboard::Key mLeftKey;
	sf::Keyboard::Key mRightKey;
	int mRotaionDirection;
	int mSize;
};

