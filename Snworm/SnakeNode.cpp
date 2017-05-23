#include "SnakeNode.h"

SnakeNode::SnakeNode(const sf::Color& snakeColor, float radius, const sf::Vector2f& position, float speed)
{
	setFillColor(snakeColor);
	setOutlineColor(sf::Color::Black);
	setPosition(position);
	this->setRadius(radius);
	setOrigin(this->getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	mSpeed = speed;
}


SnakeNode::~SnakeNode(){/*Empty*/}


void SnakeNode::move(const SnakeNode &inFront)
{
	sf::Vector2f direction;
	direction.x = inFront.getPosition().x - this->getPosition().x;
	direction.y = inFront.getPosition().y - this->getPosition().y;

	float magnitude = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	if (magnitude > (getRadius() * 2.05) && magnitude != 0)
	{
		CircleShape::move(direction.x / magnitude * mSpeed, direction.y / magnitude * mSpeed);
	}
}