#pragma once
#include <SFML\Graphics.hpp>

class Collider
{
public:
	static bool checkCollision(const sf::CircleShape & c1, const sf::CircleShape & c2);
};

