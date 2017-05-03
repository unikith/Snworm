#include "SnakeTail.h"



SnakeTail::SnakeTail(const sf::Color& snakeColor, float radius, const sf::Vector2f& position, float speed)
	: SnakeNode(snakeColor, radius, position, speed){/*Empty*/}


SnakeTail::~SnakeTail(){/*Empty*/}

void SnakeTail::move(const SnakeNode &inFront)
{
	sf::Vector2f direction;
	direction.x = inFront.getPosition().x - this->getPosition().x;
	direction.y = inFront.getPosition().y - this->getPosition().y;

	float magnitude = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	if (magnitude >= this->getRadius() * 2 && magnitude !=  0)
	{
		CircleShape::move(direction.x / magnitude * mSpeed, direction.y / magnitude * mSpeed);	
	}

}
