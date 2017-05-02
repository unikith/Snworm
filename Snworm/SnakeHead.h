#pragma once
#include "SnakeNode.h"
class SnakeHead :
	public SnakeNode
{
public:
	SnakeHead(const sf::Color& snakeColor, float radius, const sf::Vector2f& position);
	~SnakeHead();
};

