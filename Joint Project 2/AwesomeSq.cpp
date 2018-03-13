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
			if (!m_halfMove)
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 9, 32 * 7, 32, 32));
			}
			else
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 11, 32 * 7, 32, 32));
			}
		}
		else
		{
			m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 10, 32 * 7, 32, 32));
		}
	}

	if (m_playerSouth)
	{
		if (m_playerMovingDown)
		{
			if (!m_halfMove)
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 9, 32 * 4, 32, 32));
			}
			else
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 11, 32 * 4, 32, 32));
			}
		}
		else
		{
			m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 10, 32 * 4, 32, 32));
		}
	}

	if (m_playerEast)
	{
		if (m_playerMovingRight)
		{
			if (!m_halfMove)
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 9, 32 * 6, 32, 32));
			}
			else
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 11, 32 * 6, 32, 32));
			}
		}
		else
		{
			m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 10, 32 * 6, 32, 32));
		}
	}

	if (m_playerWest)
	{
		if (m_playerMovingLeft)
		{
			if (!m_halfMove)
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 9, 32 * 5, 32, 32));
			}
			else
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 11, 32 * 5, 32, 32));
			}
		}
		else
		{
			m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(32 * 10, 32 * 5, 32, 32));
		}
	}

	m_playerSprite.setTexture(m_playerTexture);
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
	m_playerSprite.setPosition(m_playerPos);
	updateSprite();
}

void AwesomeSq::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_playerSprite);
}

void AwesomeSq::setStart()
{
	m_colPlayer = 0;
	m_colPlayer = 0;
	m_playerPos = sf::Vector2f(0.0f, 0.0f);
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
