#include "Snake.h"

Snake::Snake(sf::RenderWindow & window, sf::Color snakeColor, float nodeRadius,
	float speed, float turnSpeed, sf::Keyboard::Key left, sf::Keyboard::Key right)
{
	sf::Vector2f spawnPosition (window.getSize().x / 2, window.getSize().y / 2);
	mColor = snakeColor;
	mNodeRadiuses = nodeRadius;
	mSnakeBody.push_back(new SnakeHead(mColor, mNodeRadiuses, spawnPosition, speed));
	mSnakeBody.push_back(new SnakeNode(mColor, mNodeRadiuses,
		sf::Vector2f(spawnPosition.x - 2 * nodeRadius, spawnPosition.y),
		speed));
	mSnakeBody.push_back(new SnakeNode(mColor, mNodeRadiuses, 
						sf::Vector2f(spawnPosition.x - 4 * nodeRadius, spawnPosition.y),
						speed));
	mSpeed = speed;
	mTurnSpeed = turnSpeed;
	this->mLeftKey = left;
	this->mRightKey = right;
	mRotaionDirection = 0;
	mSize = 3;
}


Snake::~Snake()
{
	for (int i = 0; i < mSnakeBody.size(); ++i)
	{
		delete mSnakeBody[i];
	}
	mSnakeBody.clear();
}

void Snake::drawInWindow(sf::RenderWindow& window)
{
	for (int i = mSnakeBody.size() - 1; i >= 0 ; --i)
	{
		window.draw((*mSnakeBody[i]));
	}
}

void Snake::move()
{
	for (int i =  mSnakeBody.size() - 1; i >= 0; i--)
	{
		if (i > 0)
		{
			mSnakeBody[i]->move(*mSnakeBody[i - 1]);
		}
		else
		{
			SnakeHead * temp = dynamic_cast<SnakeHead *>(mSnakeBody[i]);
			if (temp != nullptr)
			{
				temp->modAngle(mTurnSpeed * mRotaionDirection);
				temp->move();
			}
		}
	}
}

bool Snake::runEvent(const sf::Event & event)
{
	bool success = true;
	if (sf::Keyboard::isKeyPressed(mLeftKey) && sf::Keyboard::isKeyPressed(mRightKey))
	{
		mRotaionDirection = 0;
	}
	else if (sf::Keyboard::isKeyPressed(mLeftKey))
	{
		mRotaionDirection = 1;
	}
	else if (sf::Keyboard::isKeyPressed(mRightKey))
	{
		mRotaionDirection = -1;
	}
	else
	{
		mRotaionDirection = 0;
		success = false;
	}
	return success;
}

void Snake::spawn()
{
	mSnakeBody.insert(mSnakeBody.end() - 1, 
		new SnakeNode(mColor, mNodeRadiuses, mSnakeBody.back()->getPosition(), mSpeed));
	++mSize;
}