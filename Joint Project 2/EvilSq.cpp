// EvilSq function definitions here

#include "EvilSq.h"


/// <summary>
/// default contructer
/// </summary>
EvilSq::EvilSq()
{
	m_enemySpriteSheet.loadFromFile("ASSETS/IMAGES/beeSprites.png");
}

/// <summary>
/// returns enemy's row in maze
/// </summary>
/// <returns></returns>
int EvilSq::getEnemyRow()
{
	return m_enemyRow;
}

/// <summary>
/// returns enemy's column in maze
/// </summary>
/// <returns></returns>
int EvilSq::getEnemyCol()
{
	return m_enemyColumn;
}

/// <summary>
/// moves enemy up
/// </summary>
void EvilSq::moveUp()
{
	m_enemyPos.y -= m_enemySpeed;
}

/// <summary>
/// moves enemy down
/// </summary>
void EvilSq::moveDown()
{
	m_enemyPos.y += m_enemySpeed;
}

/// <summary>
/// moves enemy right
/// </summary>
void EvilSq::moveRight()
{
	m_enemyPos.x += m_enemySpeed;
}

/// <summary>
/// moves enemy left 
/// </summary>
void EvilSq::moveLeft()
{
	m_enemyPos.x -= m_enemySpeed;
}

/// <summary>
/// Sets the texture dependant on direction and sprite bools
/// </summary>
void EvilSq::setTexture()
{
	//enemy moving up
	if (m_enemyMovingUp)
	{
		if (m_sprite1)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 0, BLOCK_HEIGHT*3, 32, 32));
		}
		else if (m_sprite2)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 1 , BLOCK_HEIGHT * 3,  32, 32));
		}
		else if (m_sprite3)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 2, BLOCK_HEIGHT * 3, 32, 32));
		}
	}
	//end up

	//enemy moving down
	else if (m_enemyMovingDown)
	{
		if (m_sprite1)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 0, BLOCK_HEIGHT * 0, 32, 32));
		}
		else if (m_sprite2)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 1, BLOCK_HEIGHT * 0, 32, 32));
		}
		else if (m_sprite3)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 2, BLOCK_HEIGHT * 0, 32, 32));
		}
	}
	//end down

	//enemy moving right
	else if (m_enemyMovingRight)
	{
		if (m_sprite1)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 0, BLOCK_HEIGHT * 2, 32, 32));
		}
		else if (m_sprite2)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 1, BLOCK_HEIGHT * 2, 32, 32));
		}
		else if (m_sprite3)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 2, BLOCK_HEIGHT * 2, 32, 32));
		}
	}
	//end right

	//enemy moving left
	else if (m_enemyMovingLeft)
	{
		if (m_sprite1)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 0, BLOCK_HEIGHT * 1, 32, 32));
		}
		else if (m_sprite2)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 1, BLOCK_HEIGHT * 1, 32, 32));
		}
		else if (m_sprite3)
		{
			m_enemyTexture.loadFromImage(m_enemySpriteSheet, sf::IntRect(BLOCK_WIDTH * 0, BLOCK_HEIGHT * 0, 32, 32));
		}
	}
	//end left
	setSprite();
}

bool EvilSq::getMoveUp()
{
	return m_enemyMovingUp;
}

bool EvilSq::getMoveDown()
{
	return m_enemyMovingDown;
}

bool EvilSq::getMoveLeft()
{
	return m_enemyMovingLeft;
}

bool EvilSq::getMoveRight()
{
	return m_enemyMovingRight;
}

void EvilSq::setMoveUp()
{
	m_enemyMovingUp = true;
	m_enemyMovingDown = false;
	m_enemyMovingLeft = false;
	m_enemyMovingRight = false;
}

void EvilSq::setMoveDown()
{
	m_enemyMovingUp = false;
	m_enemyMovingDown = true;
	m_enemyMovingLeft = false;
	m_enemyMovingRight = false;
}

void EvilSq::setMoveLeft()
{
	m_enemyMovingUp = false;
	m_enemyMovingDown = false;
	m_enemyMovingLeft = true;
	m_enemyMovingRight = false;
}

void EvilSq::setMoveRight()
{
	m_enemyMovingUp = false;
	m_enemyMovingDown = false;
	m_enemyMovingLeft = false;
	m_enemyMovingRight = true;
}




//sets the enemy sprite
void EvilSq::setSprite()
{
	m_enemySprite.setTexture(m_enemyTexture);
}