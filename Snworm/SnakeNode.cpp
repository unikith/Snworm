#include "SnakeNode.h"

SnakeNode::SnakeNode(const sf::Color& snakeColor, float radius, const sf::Vector2f& position, float speed)
{
	setFillColor(snakeColor);
	setOutlineColor(sf::Color::Black);
	setPosition(position);
	this->setRadius(radius);
	setOrigin(this->getGlobalBounds().width, getGlobalBounds().height);
	mSpeed = speed;
}


SnakeNode::~SnakeNode(){/*Empty*/}


void SnakeNode::move(const SnakeNode &inFront)
{
	sf::Vector2f direction;
	direction.x = inFront.getPosition().x - this->getPosition().x;
	direction.y = inFront.getPosition().y - this->getPosition().y;

	float magnitude = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	if (magnitude != 0) // prevents divide by 0 error
	{
		mVelocity.x = direction.x / magnitude * mSpeed;
		mVelocity.y = direction.y / magnitude * mSpeed;
	}
	
	CircleShape::move(mVelocity.x, mVelocity.y);
}