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
	setRowCol(-4, -4);
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

//move enemy
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
		m_enemyMovingUp = false;
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
		m_enemyMovingDown = false;
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
		m_enemyMovingRight = false;
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
		m_enemyMovingLeft =false;
	}
	
}

//is enemy moving
bool EvilSq::moving()
{
	if (m_enemyMovingDown || m_enemyMovingLeft || m_enemyMovingRight || m_enemyMovingUp)
	{
		m_moving = true;
	}
	else
	{
		m_moving = false;
	}
	return m_moving;
}

//set start pos with row/ col
void EvilSq::setRowCol(int t_row, int t_col)
{
	m_enemyRow = t_row;
	m_enemyColumn = t_col;
	m_enemyDistInCell = 0;
	m_enemyPos = sf::Vector2f(m_enemyColumn*BLOCK_WIDTH, m_enemyRow* BLOCK_HEIGHT);
	setPos();
}

//set enemy pos
void EvilSq::setPos()
{
	m_enemySprite.setPosition(m_enemyPos);
}

//return enemy pos
sf::Vector2f EvilSq::getPos()
{
	return m_enemyPos;
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
	if (!m_enemyAlive)
	{
		m_enemyTexture.loadFromFile("ASSETS/IMAGES/beeDead.png");
	}
	setSprite();
}

//enemy move up
bool EvilSq::getMoveUp()
{
	return m_enemyMovingUp;
}

//enemy move down
bool EvilSq::getMoveDown()
{
	return m_enemyMovingDown;
}

//enemy move left
bool EvilSq::getMoveLeft()
{
	return m_enemyMovingLeft;
}

//enemy move right
bool EvilSq::getMoveRight()
{
	return m_enemyMovingRight;
}

//set up bool true, others to false
void EvilSq::setMoveUp()
{
	m_enemyMovingUp = true;
	m_up = true;
	m_enemyMovingDown = false;
	m_down = false;
	m_enemyMovingLeft = false;
	m_left = false;
	m_enemyMovingRight = false;
	m_right = false;
}

//set down bool true, others to false
void EvilSq::setMoveDown()
{
	m_enemyMovingUp = false;
	m_up = false;
	m_enemyMovingDown = true;
	m_down = true;
	m_enemyMovingLeft = false;
	m_left = false;
	m_enemyMovingRight = false;
	m_right = false;
}

//set left bool true, others to false
void EvilSq::setMoveLeft()
{
	m_enemyMovingUp = false;
	m_up = false;
	m_enemyMovingDown = false;
	m_down = false;
	m_enemyMovingLeft = true;
	m_left = true;
	m_enemyMovingRight = false;
	m_right = false;
}

//set right bool true, others to false
void EvilSq::setMoveRight()
{
	m_enemyMovingUp = false;
	m_up = false;
	m_enemyMovingDown = false;
	m_down = false;
	m_enemyMovingLeft = false;
	m_left = false;
	m_enemyMovingRight = true;
	m_right = true;
}

//set moving bools
void EvilSq::setBools()
{
	if (m_up)
	{
		m_enemyMovingUp = true;
	}
	if (m_down)
	{
		m_enemyMovingDown = true;
	}
	if (m_left)
	{
		m_enemyMovingLeft = true;
	}
	if (m_right)
	{
		m_enemyMovingRight = true;
	}
}


//return alive bool
bool EvilSq::getAlive()
{
	return m_enemyAlive;
}

//set enemy alive
void EvilSq::setAlive()
{
	m_enemyAlive = true;
}

//set dead
void EvilSq::setDead()
{
	m_enemyAlive = false;
}

//draw enemy
void EvilSq::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemySprite);
}

//get enemy sprite
sf::Sprite EvilSq::getSprite()
{
	return m_enemySprite;
}


//sets the enemy sprite
void EvilSq::setSprite()
{
	m_enemySprite.setTexture(m_enemyTexture);
}