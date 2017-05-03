#pragma once
#include "SnakeNode.h"
class SnakeTail :
	public SnakeNode
{
public:
	SnakeTail(const sf::Color& snakeColor, float radius, const sf::Vector2f& position, float speed);
	~SnakeTail();

	void move(const SnakeNode &inFront);
};

