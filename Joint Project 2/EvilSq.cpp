// EvilSq function definitions here

#include "EvilSq.h"


/// <summary>
/// default contructer
/// </summary>
EvilSq::EvilSq()
{
	m_enemySpriteSheet.loadFromFile("ASSETS/IMAGES/beeSprites.png");
	m_sprite1 = true;
	m_sprite2 = false;
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

void EvilSq::move()
{
	if (m_enemyMovingDown)
	{
		moveDown();
	}
	if (m_enemyMovingLeft)
	{
		moveLeft();
	}
	if (m_enemyMovingRight)
	{
		moveRight();
	}
	if (m_enemyMovingUp)
	{
		moveUp();
	}
	
	setPos();
	setTexture();
}

/// <summary>
/// moves enemy up
/// </summary>
void EvilSq::moveUp()
{
	m_enemyDistInCell++;
	m_enemyPos.y--;
	if (m_enemyDistInCell == 32)
	{
		m_enemyDistInCell = 0;
		m_enemyRow--;
	}
	if (m_enemyDistInCell % 4 == 0)
	{
		m_sprite1 = true;
		m_sprite2 = false;
	}
	else
	{
		m_sprite2 = true;
		m_sprite1 = false;
	}
	
}

/// <summary>
/// moves enemy down
/// </summary>
void EvilSq::moveDown()
{
	m_enemyDistInCell++;
	m_enemyPos.y++;
	if (m_enemyDistInCell == 32)
	{
		m_enemyDistInCell = 0;
		m_enemyRow++;
	}
	if (m_enemyDistInCell % 4 == 0)
	{
		m_sprite1 = true;
		m_sprite2 = false;
	}
	else
	{
		m_sprite2 = true;
		m_sprite1 = false;
	}
	
}

/// <summary>
/// moves enemy right
/// </summary>
void EvilSq::moveRight()
{
	m_enemyDistInCell++;
	m_enemyPos.x++;
	if (m_enemyDistInCell == 32)
	{
		m_enemyDistInCell = 0;
		m_enemyColumn++;
	}
	if (m_enemyDistInCell % 4== 0)
	{
		m_sprite1 = true;
		m_sprite2 = false;
	}
	else
	{
		m_sprite2 = true;
		m_sprite1 = false;
	}
	
}

/// <summary>
/// moves enemy left 
/// </summary>
void EvilSq::moveLeft()
{
	m_enemyDistInCell++;
	m_enemyPos.x--;
	if (m_enemyDistInCell % 4 == 0)
	{
		m_sprite1=true;
		m_sprite2 = false;
	}
	else
	{
		m_sprite2 = true;
		m_sprite1 = false;
	}
	
	
	if (m_enemyDistInCell == 32)
	{
		m_enemyDistInCell = 0;
		m_enemyColumn--;
	}
	
}

void EvilSq::setRowCol(int t_row, int t_col)
{
	m_enemyRow = t_row;
	m_enemyColumn = t_col;
	m_enemyPos = sf::Vector2f(m_enemyRow*BLOCK_WIDTH, m_enemyColumn* BLOCK_HEIGHT);
	setPos();
}

void EvilSq::setPos()
{
	m_enemySprite.setPosition(m_enemyPos);
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

bool EvilSq::getAlive()
{
	return m_enemyAlive;
}

void EvilSq::setAlive()
{
	m_enemyAlive = true;
}

void EvilSq::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemySprite);
}




//sets the enemy sprite
void EvilSq::setSprite()
{
	m_enemySprite.setTexture(m_enemyTexture);
}