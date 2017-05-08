#include "Collider.h"


bool Collider::checkCollision(const sf::CircleShape & c1, const sf::CircleShape & c2)
{
	bool didCollide = false;
	sf::Vector2f direction;
	direction.x = c1.getPosition().x - c2.getPosition().x;
	direction.y = c1.getPosition().y - c2.getPosition().y;

	float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	if (distance < c1.getRadius() + c2.getRadius())
	{
		didCollide = true;
	}
	return didCollide;
}
