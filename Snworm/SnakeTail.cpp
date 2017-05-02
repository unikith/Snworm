#include "SnakeTail.h"



SnakeTail::SnakeTail(const sf::Color& snakeColor, float radius, const sf::Vector2f& position) 
	: SnakeNode(snakeColor, radius, position)
{
	mSpawnsInQueue = 0;
}


SnakeTail::~SnakeTail(){/*Empty*/}
