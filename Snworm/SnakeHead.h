#pragma once
#include "SnakeNode.h"

#include <cmath>

#define PI 3.14159

class SnakeHead :
	public SnakeNode
{
public:
	SnakeHead(const sf::Color& snakeColor, float radius, const sf::Vector2f& position, float speed);
	~SnakeHead();
	void move();
	void modAngle(const float degreeChange);
protected:
	float mAngleRads;
};

