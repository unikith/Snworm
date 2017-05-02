#include "Snake.h"



Snake::Snake(sf::Color snakeColor, float nodeRadius, sf::Vector2f spawnPosition)
{
	mColor = snakeColor;
	mNodeRadiuses = nodeRadius;
	mSnakeBody.push_back(new SnakeHead(mColor, mNodeRadiuses, spawnPosition));
	mSnakeBody.push_back(new SnakeTail(mColor, mNodeRadiuses, 
						sf::Vector2f(spawnPosition.x + nodeRadius, spawnPosition.y)));
}


Snake::~Snake()
{
	for (int i = 0; i < mSnakeBody.size(); ++i)
	{
		delete mSnakeBody[i];
	}
	mSnakeBody.clear();
}
