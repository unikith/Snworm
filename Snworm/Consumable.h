#pragma once
#include "SFML\Graphics.hpp"
#include <cstdlib>

class Consumable : public sf::CircleShape
{
public:
	Consumable(const sf::RenderWindow & window, sf::Color Color = sf::Color::White, float radius = 12);
	~Consumable();
};

