#pragma once
#include "SnakeNode.h"
class SnakeTail :
	public SnakeNode
{
public:
	SnakeTail(const sf::Color& snakeColor, float radius, const sf::Vector2f& position);
	~SnakeTail();
private:
	int mSpawnsInQueue;
};

