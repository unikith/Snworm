#include "SnakeHead.h"



SnakeHead::SnakeHead(const sf::Color& snakeColor, float radius, const sf::Vector2f& position, float speed)
	: SnakeNode(snakeColor, radius, position, speed)
{
	mVelocity.x = speed;
	mVelocity.y = 0;
}


SnakeHead::~SnakeHead(){/*Empty*/}

void SnakeHead::move()
{
	CircleShape::move(mVelocity.x, mVelocity.y);
}
