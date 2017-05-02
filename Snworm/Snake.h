#pragma once
#include <vector>

#include "SnakeHead.h"
#include "SnakeTail.h"

using std::vector;

class Snake
{
public:
	Snake(sf::Color snakeColor, float nodeRadius, sf::Vector2f spawnPosition);
	~Snake();
private:
	vector<SnakeNode *> mSnakeBody;
	sf::Color mColor;
	float mNodeRadiuses;
};

