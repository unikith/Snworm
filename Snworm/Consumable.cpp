#include "Consumable.h"

Consumable::Consumable(const sf::RenderWindow & window, sf::Color color, float radius)
{
	setFillColor(color);
	setRadius(radius);
	setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	setPosition(sf::Vector2f((rand() % (window.getSize().x - (2 * int(radius)))) + radius,
		(rand() % (window.getSize().y - (2 * int(radius)))) +  radius));
}


Consumable::~Consumable() {/*Empty*/}

