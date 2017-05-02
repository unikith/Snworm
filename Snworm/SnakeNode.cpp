#include "SnakeNode.h"

SnakeNode::SnakeNode(const sf::Color& snakeColor, float radius, const sf::Vector2f& position)
{
	setFillColor(snakeColor);
	setOutlineColor(sf::Color::Black);
	setPosition(position);
	this->setRadius(radius);
	setOrigin(this->getGlobalBounds().width, getGlobalBounds().height);
}


SnakeNode::~SnakeNode(){/*Empty*/}
