// AwesomeSq function definitions here

#include "AwesomeSq.h"

AwesomeSq::AwesomeSq()
{
	m_spriteSheet.loadFromFile("ASSETS/IMAGES/playerCharacters.png");
	m_playerSouth = true;
	m_playerEast = false;
	m_playerNorth = false;
	m_playerWest = false;
}

void AwesomeSq::updateSprite()
{
	if (m_playerNorth)
	{
		if (m_playerMovingUp)
		{
			if (true)
			{

			}
		}
		else
		{
			m_playerTexture.loadFromFile("ASSETS/IMAGES/playerCharacters", sf::IntRect(32 * 10, 32 * 7, 32, 32));
		}
	}
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
	m_playerSouth = false;
	m_playerEast = false;
	m_playerNorth = true;
	m_playerWest = false;
}

void AwesomeSq::keyDown()
{
	m_rowPlayer++;
	m_playerMovingDown = true;
	m_playerSouth = true;
	m_playerEast = false;
	m_playerNorth = false;
	m_playerWest = false;
}

void AwesomeSq::keyLeft()
{
	m_colPlayer--;
	m_playerMovingLeft = true;
	m_playerSouth = false;
	m_playerEast = false;
	m_playerNorth = false;
	m_playerWest = true;
}

void AwesomeSq::keyRight()
{
	m_playerMovingRight = true;
	m_colPlayer++;
	m_playerSouth = false;
	m_playerEast = true;
	m_playerNorth = false;
	m_playerWest = false;
	
}

void AwesomeSq::moveUp()
{
	m_playerPos.y--;
	m_halfMovePix++;
	if (m_halfMovePix >= 16)
	{
		m_halfMove = true;
	}
	if (m_playerPos.y == m_rowPlayer*BLOCK_HEIGHT)
	{
		m_playerMovingUp = false;
		m_halfMove = false;
		m_halfMovePix = 0;
	}
	setPos();
}

void AwesomeSq::moveDown()
{
	m_playerPos.y++;
	m_halfMovePix++;
	if (m_halfMovePix >=16 )
	{
		m_halfMove = true;
	}
	if (m_playerPos.y == m_rowPlayer*BLOCK_HEIGHT)
	{
		m_playerMovingDown = false;
		m_halfMove = false;
		m_halfMovePix = 0;
	}
	setPos();
}

void AwesomeSq::moveLeft()
{
	m_playerPos.x--;
	m_halfMovePix++;
	if (m_halfMovePix >= 16)
	{
		m_halfMove = true;
	}
	if (m_playerPos.x == m_colPlayer*BLOCK_WIDTH)
	{
		m_playerMovingLeft = false;
		m_halfMove = false;
		m_halfMovePix = 0;
	}
	setPos();
}

void AwesomeSq::moveRight()
{
	m_playerPos.x++;
	m_halfMovePix++;
	if (m_halfMovePix >= 16)
	{
		m_halfMove = true;
	}
	if (m_playerPos.x == m_colPlayer*BLOCK_WIDTH)
	{
		m_playerMovingRight = false;
		m_halfMove = false;
		m_halfMovePix = 0;
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
