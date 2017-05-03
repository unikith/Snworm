#pragma once
#include <SFML\Graphics.hpp>
/*
* This class is used for the extendable parts of the snake
* The SnakeHead and SnakeTail class derive from this class
*/
class SnakeNode :
	public sf::CircleShape
{
public:
	SnakeNode(const sf::Color& snakeColor, float radius, const sf::Vector2f& position, float speed);
	virtual ~SnakeNode();

	virtual void move(const SnakeNode &inFront);
protected:
	float mSpeed;
};

