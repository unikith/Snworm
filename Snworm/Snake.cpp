#include "Snake.h"



Snake::Snake(sf::Color snakeColor, float nodeRadius, sf::Vector2f spawnPosition, float speed)
{
	mColor = snakeColor;
	mNodeRadiuses = nodeRadius;
	mSnakeBody.push_back(new SnakeHead(mColor, mNodeRadiuses, spawnPosition, speed));
	mSnakeBody.push_back(new SnakeTail(mColor, mNodeRadiuses, 
						sf::Vector2f(spawnPosition.x - 4 * nodeRadius, spawnPosition.y), speed));
	mSpeed = speed;
}


Snake::~Snake()
{
	for (int i = 0; i < mSnakeBody.size(); ++i)
	{
		delete mSnakeBody[i];
	}
	mSnakeBody.clear();
}

void Snake::drawInWindow(sf::RenderWindow& window)
{
	for (int i = mSnakeBody.size() - 1; i >= 0 ; --i)
	{
		window.draw((*mSnakeBody[i]));
	}
}

void Snake::move()
{
	for (int i = 0; i < mSnakeBody.size(); i++)
	{
		if (i > 0)
		{
			mSnakeBody[i]->move(*mSnakeBody[i - 1]);
		}
		else
		{
			dynamic_cast<SnakeHead *>(mSnakeBody[i])->move();
		}
	}
}
