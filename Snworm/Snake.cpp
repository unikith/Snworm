#include "Snake.h"

Snake::Snake(sf::Vector2f spawnPosition, sf::Color snakeColor, float nodeRadius,
	float speed, float turnSpeed, sf::Keyboard::Key left, sf::Keyboard::Key right)
{
	mColor = snakeColor;
	mNodeRadiuses = nodeRadius;
	mSnakeBody.push_back(new SnakeHead(mColor, mNodeRadiuses, spawnPosition, speed));
	mSnakeBody.push_back(new SnakeNode(mColor, mNodeRadiuses,
		sf::Vector2f(spawnPosition.x - 2 * nodeRadius, spawnPosition.y),
		speed));
	mSnakeBody.push_back(new SnakeTail(mColor, mNodeRadiuses, 
						sf::Vector2f(spawnPosition.x - 4 * nodeRadius, spawnPosition.y),
						speed));
	mSpeed = speed;
	mTurnSpeed = turnSpeed;
	this->mLeftKey = left;
	this->mRightKey = right;
	mHoldLeft = false;
	mHoldRight = false;
	mRotaionDirection = 0;
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
	bool success = false;
	if (event.type == sf::Event::KeyPressed)
	{
		success = keyPress(event);
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		success = keyRelease(event);
	}
	return success;
}

void Snake::spawn()
{
	mSnakeBody.insert(mSnakeBody.end() - 1, 
		new SnakeNode(mColor, mNodeRadiuses, mSnakeBody.back()->getPosition(), mSpeed));
}

SnakeNode & Snake::getHead() const
{
	return *mSnakeBody[0];
}

bool Snake::keyPress(const sf::Event event)
{
	bool success = false;
	if (event.key.code == mLeftKey)
	{
		success = true;
		startLeft();
	}
	else if (event.key.code == mRightKey)
	{
		success = true;
		startRight();
	}
	return success;
}

bool Snake::keyRelease(const sf::Event event)
{
	bool success = false;
	if (event.key.code == mLeftKey)
	{
		success = true;
		stopLeft();
	}
	else if (event.key.code == mRightKey)
	{
		success = true;
		stopRight();
	}
	return success;
}

void Snake::startLeft()
{
	if (!mHoldLeft)
	{
		mRotaionDirection = 1;
	}
	mHoldLeft = true;
}

void Snake::startRight()
{
	if (!mHoldRight)
	{
		mRotaionDirection = -1;
	}
	mHoldRight = true;
}

void Snake::stopLeft()
{
	if (mHoldRight && mRotaionDirection > 0)
	{
		mRotaionDirection = -1;
	}
	else if (!mHoldRight)
	{
		mRotaionDirection = 0;
	}
	mHoldLeft = false;
}

void Snake::stopRight()
{
	if (mHoldLeft && mRotaionDirection < 0)
	{
		mRotaionDirection = 1;
	}
	else if (!mHoldLeft)
	{
		mRotaionDirection = 0;
	}
	mHoldRight = 0;
}