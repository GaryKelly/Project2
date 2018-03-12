// AwesomeSq function definitions here

#include "AwesomeSq.h"

AwesomeSq::AwesomeSq()
{
}

int AwesomeSq::getRow()
{
	return m_rowPlayer;
}

int AwesomeSq::getCol()
{
	return m_colPlayer;
}

void AwesomeSq::keyUp()
{
	m_rowPlayer--;
	m_playerMovingUp = true;
}

void AwesomeSq::keyDown()
{
	m_rowPlayer++;
	m_playerMovingDown = true;
}

void AwesomeSq::keyLeft()
{
	m_colPlayer--;
	m_playerMovingLeft = true;
}

void AwesomeSq::keyRight()
{
	m_playerMovingRight = true;
	m_colPlayer++;
	
}

void AwesomeSq::moveUp()
{
	m_playerPos.y--;
	if (m_playerPos.y == m_rowPlayer*BLOCK_HEIGHT)
	{
		m_playerMovingUp = false;
	}
	setPos();
}

void AwesomeSq::moveDown()
{
	m_playerPos.y++;
	if (m_playerPos.y == m_rowPlayer*BLOCK_HEIGHT)
	{
		m_playerMovingDown = false;
	}
	setPos();
}

void AwesomeSq::moveLeft()
{
	m_playerPos.x--;
	if (m_playerPos.x == m_colPlayer*BLOCK_WIDTH)
	{
		m_playerMovingLeft = false;
	}
	setPos();
}

void AwesomeSq::moveRight()
{
	m_playerPos.x++;
	if (m_playerPos.x == m_colPlayer*BLOCK_WIDTH)
	{
		m_playerMovingRight = false;
	}
	setPos();
}

void AwesomeSq::setPos()
{
	m_playerShape.setPosition(m_playerPos);
}

void AwesomeSq::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_playerShape);
}

void AwesomeSq::setStart()
{
	m_colPlayer = 0;
	m_colPlayer = 0;
	m_playerPos = sf::Vector2f(0.0f, 0.0f);
	m_playerShape.setFillColor(sf::Color::Red);
	setPos();
}

bool AwesomeSq::playerMovingRight()
{
	return m_playerMovingRight;
}

bool AwesomeSq::playerMovingLeft()
{
	return m_playerMovingLeft;
}

bool AwesomeSq::playerMovingUp()
{
	return m_playerMovingUp;
}

bool AwesomeSq::playerMovingDown()
{
	return m_playerMovingDown;
}
