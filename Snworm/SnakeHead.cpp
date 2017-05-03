#include "SnakeHead.h"



SnakeHead::SnakeHead(const sf::Color& snakeColor, float radius, const sf::Vector2f& position, float speed)
	: SnakeNode(snakeColor, radius, position, speed)
{
	mAngleRads = 6;
}


SnakeHead::~SnakeHead(){/*Empty*/}

void SnakeHead::move()
{
	CircleShape::move(cos(mAngleRads) * mSpeed , sin(mAngleRads) * mSpeed);
}

void SnakeHead::modAngle(const float degreeChange)
{
	mAngleRads += degreeChange;
}
