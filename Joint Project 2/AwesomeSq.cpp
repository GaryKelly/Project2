// AwesomeSq function definitions here

#include "AwesomeSq.h"

/// <summary>
/// default constructor
/// </summary>
AwesomeSq::AwesomeSq()
{
	m_spriteSheet.loadFromFile("ASSETS/IMAGES/playerCharacters.png");
	m_playerSouth = true;
	m_playerEast = false;
	m_playerNorth = false;
	m_playerWest = false;
	m_lives = 3;
}

/// <summary>
/// updates sprite with direction and movement
/// </summary>
void AwesomeSq::updateSprite()
{
	if (m_playerNorth) //is player facing north
	{
		if (m_playerMovingUp) //is player moving up
		{
			if (!m_halfMove) //has player not yet reached the halfway mark of movement
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 9, BLOCK_HEIGHT * 7, BLOCK_WIDTH, BLOCK_HEIGHT));
			}
			else
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 11, BLOCK_HEIGHT * 7, BLOCK_WIDTH, BLOCK_HEIGHT));
			}
		}
		else
		{
			m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 10, BLOCK_HEIGHT * 7, BLOCK_WIDTH, BLOCK_HEIGHT));
		}
	}

	if (m_playerSouth) //is player facing south
	{
		if (m_playerMovingDown) //is the player moving down
		{
			if (!m_halfMove)//has player not yet reached the halfway mark of movement
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 9, BLOCK_HEIGHT * 4, BLOCK_WIDTH, BLOCK_HEIGHT));
			}
			else
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 11, BLOCK_HEIGHT * 4, BLOCK_WIDTH, BLOCK_HEIGHT));
			}
		}
		else
		{
			m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 10, BLOCK_HEIGHT * 4, BLOCK_WIDTH, BLOCK_HEIGHT));
		}
	}

	if (m_playerEast) //is player facing east
	{
		if (m_playerMovingRight) //is player moving right
		{
			if (!m_halfMove)//has player not yet reached the halfway mark of movement
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 9, BLOCK_HEIGHT * 6, BLOCK_WIDTH, BLOCK_HEIGHT));
			}
			else
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 11, BLOCK_HEIGHT * 6, BLOCK_WIDTH, BLOCK_HEIGHT));
			}
		}
		else
		{
			m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 10, BLOCK_HEIGHT * 6, BLOCK_WIDTH, BLOCK_HEIGHT));
		}
	}

	if (m_playerWest) //is player facing west
	{
		if (m_playerMovingLeft) //is player moving left
		{
			if (!m_halfMove)//has player not yet reached the halfway mark of movement
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 9, BLOCK_HEIGHT * 5, BLOCK_WIDTH, BLOCK_HEIGHT));
			}
			else
			{
				m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 11, BLOCK_HEIGHT * 5, BLOCK_WIDTH, BLOCK_HEIGHT));
			}
		}
		else
		{
			m_playerTexture.loadFromImage(m_spriteSheet, sf::IntRect(BLOCK_WIDTH * 10, BLOCK_HEIGHT * 5, BLOCK_WIDTH, BLOCK_HEIGHT));
		}
	}

	m_playerSprite.setTexture(m_playerTexture);
}

/// <summary>
/// returns the row the player is on the maze
/// </summary>
/// <returns></returns>
int AwesomeSq::getRow()
{
	return m_rowPlayer;
}

/// <summary>
/// returns the column the player is on maze
/// </summary>
/// <returns></returns>
int AwesomeSq::getCol()
{
	return m_colPlayer;
}

/// <summary>
/// for when user presses up arrow
/// </summary>
void AwesomeSq::keyUp()
{
	m_rowPlayer--;
	m_playerMovingUp = true;
}

/// <summary>
/// sets north true and others to false
/// </summary>
void AwesomeSq::changeToUp()
{
	m_playerSouth = false;
	m_playerEast = false;
	m_playerNorth = true;
	m_playerWest = false;
}

/// <summary>
/// for when user presses down arrow
/// </summary>
void AwesomeSq::keyDown()
{
	m_rowPlayer++;
	m_playerMovingDown = true;
}

/// <summary>
/// sets south true and others false
/// </summary>
void AwesomeSq::changeToDown()
{
	m_playerSouth = true;
	m_playerEast = false;
	m_playerNorth = false;
	m_playerWest = false;
}

/// <summary>
/// for when player presses left
/// </summary>
void AwesomeSq::keyLeft()
{
	m_colPlayer--;
	m_playerMovingLeft = true;
}


/// <summary>
///  sets West true and others false
/// </summary>
void AwesomeSq::changeToLeft()
{
	m_playerSouth = false;
	m_playerEast = false;
	m_playerNorth = false;
	m_playerWest = true;
}


/// <summary>
/// for when player presses right
/// </summary>
void AwesomeSq::keyRight()
{
	m_playerMovingRight = true;
	m_colPlayer++;
}

/// <summary>
///  sets East true and others false
/// </summary>
void AwesomeSq::changeToRight()
{
	m_playerSouth = false;
	m_playerEast = true;
	m_playerNorth = false;
	m_playerWest = false;
}


/// <summary>
/// moves player up a cell
/// </summary>
void AwesomeSq::moveUp()
{
	m_playerPos.y--;
	m_halfMovePix++;
	if (m_halfMovePix >= 16)
	{
		m_halfMove = true;
	}
	if (m_halfMovePix == 32)
	{
		m_playerMovingUp = false;
		m_halfMove = false;
		m_halfMovePix = 0;
	}
	setPos();
}

/// <summary>
/// moves player down 
/// </summary>
void AwesomeSq::moveDown()
{
	m_playerPos.y++;
	m_halfMovePix++;
	if (m_halfMovePix >=16 )
	{
		m_halfMove = true;
	}
	if (m_halfMovePix == 32)
	{
		m_playerMovingDown = false;
		m_halfMove = false;
		m_halfMovePix = 0;
	}
	setPos();
}

/// <summary>
/// moves player left
/// </summary>
void AwesomeSq::moveLeft()
{
	m_playerPos.x--;
	m_halfMovePix++;
	if (m_halfMovePix >= 16)
	{
		m_halfMove = true;
	}
	if (m_halfMovePix == 32)
	{
		m_playerMovingLeft = false;
		m_halfMove = false;
		m_halfMovePix = 0;
	}
	setPos();
}

/// <summary>
/// moves player right
/// </summary>
void AwesomeSq::moveRight()
{
	m_playerPos.x++;
	m_halfMovePix++;
	if (m_halfMovePix >= 16)
	{
		m_halfMove = true;
	}
	if (m_halfMovePix == 32)
	{
		m_playerMovingRight = false;
		m_halfMove = false;
		m_halfMovePix = 0;
	}
	setPos();
}

/// <summary>
/// sets player position
/// </summary>
void AwesomeSq::setPos()
{
	m_playerSprite.setPosition(m_playerPos);
}

void AwesomeSq::setBoolsFalse()
{
	int time = 0;
	m_playerMovingDown = false;
	m_playerMovingLeft = false;
	m_playerMovingRight = false;
	m_playerMovingUp = false;
	m_halfMovePix = 0;
}

sf::Vector2f AwesomeSq::getPos()
{
	return m_playerPos;
}

/// <summary>
/// draws player on screen
/// </summary>
/// <param name="t_window"></param>
void AwesomeSq::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_playerSprite);
}

/// <summary>
/// sets starting pos of player
/// </summary>
void AwesomeSq::setStart()
{
	m_colPlayer = 1;
	m_rowPlayer = 1;
	m_playerPos = sf::Vector2f(BLOCK_HEIGHT, BLOCK_WIDTH);
	setPos();
}

/// <summary>
/// returns true is player is moving right
/// </summary>
/// <returns></returns>
bool AwesomeSq::playerMovingRight()
{
	return m_playerMovingRight;
}

/// <summary>
/// returns true is player is moving left
/// </summary>
/// <returns></returns>
bool AwesomeSq::playerMovingLeft()
{
	return m_playerMovingLeft;
}

/// <summary>
/// returns true is player is moving Up
/// </summary>
/// <returns></returns>
bool AwesomeSq::playerMovingUp()
{
	return m_playerMovingUp;
}

/// <summary>
/// returns true is player is moving down
/// </summary>
/// <returns></returns>
bool AwesomeSq::playerMovingDown()
{
	return m_playerMovingDown;
}

/// <summary>
/// returns true if player is moving 
/// </summary>
/// <returns></returns>
bool AwesomeSq::isPlayerMoving()
{
	if (m_playerMovingDown || m_playerMovingLeft || m_playerMovingRight || m_playerMovingUp)
	{
		m_moving = true;
	}
	else
	{
		m_moving = false;
	}
	
	return m_moving;
}

bool AwesomeSq::playerUp()
{
	return m_playerNorth;
}

bool AwesomeSq::playerDown()
{
	return m_playerSouth;
}

bool AwesomeSq::playerLeft()
{
	return m_playerWest;
}

bool AwesomeSq::playerRight()
{
	return m_playerEast;
}

void AwesomeSq::loseLife()
{
	m_lives--;
}

int AwesomeSq::getLives()
{
	return m_lives;
}

sf::Sprite AwesomeSq::getSprite()
{
	return m_playerSprite;
}
