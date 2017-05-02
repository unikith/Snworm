#include "SnakeTail.h"



SnakeTail::SnakeTail(const sf::Color& snakeColor, float radius, const sf::Vector2f& position, float speed)
	: SnakeNode(snakeColor, radius, position, speed)
{
	mSpawnsInQueue = 0;
	mIsSpawning = false;
}


SnakeTail::~SnakeTail(){/*Empty*/}

void SnakeTail::move(const SnakeNode &inFront)
{
	if (!mIsSpawning)
	{
		SnakeNode::move(inFront);
	}
	else
	{
		// fill in here
	}
}
