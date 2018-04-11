#include "WorldSq.h"

void cell::setPos()
{
	m_squareSprite.setPosition(m_blockPos);
}

/// <summary>
/// returns true if cell is a wall
/// </summary>
/// <returns></returns>
bool cell::getWall()
{
	return m_wall;
}

/// <summary>
/// sets cell as wall
/// </summary>
void cell::setWall()
{
	m_wall = true;
}

/// <summary>
/// sets cell as empty
/// </summary>
void cell::setWallFalse()
{
	m_wall = false;
}

/// <summary>
/// return true is cell as movable block
/// </summary>
/// <returns></returns>
bool cell::moveable()
{
	return m_moveableBlock;
}

/// <summary>
/// sets cell as movable nblock
/// </summary>
void cell::setMoveable()
{
	m_moveableBlock = true;
}

/// <summary>
/// draws individual cells
/// </summary>
/// <param name="t_window"></param>
void cell::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_squareSprite);
}

/// <summary>
/// sets textures cell
/// </summary>
void cell::setTexture()
{
	if (m_moveableBlock)
	{
		m_squareTexture.loadFromFile("ASSETS/IMAGES/moveBlock.png");
	}
	if (m_wall == true) //is cell a wall
	{
		m_squareTexture.loadFromFile("ASSETS/IMAGES/wall.png");
	}
	else if (m_wall == false) //is cell not a wall
	{
		m_squareTexture.loadFromFile("ASSETS/IMAGES/floor.png");
	}
	
	

	
	setSprite();
}


/// <summary>
/// assign texture to sprite
/// </summary>
void cell::setSprite()
{
	m_squareSprite.setTexture(m_squareTexture);
}

/// <summary>
/// sets cell pos
/// </summary>
/// <param name="t_row"></param>
/// <param name="t_col"></param>
void cell::setPos(int t_row, int t_col)
{
	m_blockPos.x = BLOCK_WIDTH * t_col;
	m_blockPos.y = BLOCK_HEIGHT * t_row;
	m_squareSprite.setPosition(m_blockPos);

}

sf::Vector2f cell::getPos()
{
	return m_blockPos;
}

void cell::setUp()
{
	m_up = true;
}

void cell::setDown()
{
	m_down = true;
}

void cell::setRight()
{
	m_right = true;
}

void cell::setLeft()
{
	m_left = true;
}

void cell::moveBlock()
{

	if (m_up)
	{
		
		if (m_pixels <= 32)
		{
			m_blockPos.y--;
			m_pixels++;
		}
		else
		{
			m_moved = true;
			m_framesSinceMove++;
		}
		if (m_moved && m_framesSinceMove >= 300 )
		{
			m_blockPos.y++;
			if (m_framesSinceMove == 332)
			{
				m_moved = false;
				m_framesSinceMove = 0;
				m_up = false;
				m_pixels = 0;
			}
		}

	}
	if (m_down)
	{
		if (m_pixels <= 32)
		{
			m_blockPos.y++;
			m_pixels++;
		}
		else
		{
			m_moved = true;
			m_framesSinceMove++;
		}
		if (m_moved && m_framesSinceMove >= 300)
		{
			m_blockPos.y--;
			if (m_framesSinceMove == 332)
			{
				m_moved = false;
				m_framesSinceMove = 0;
				m_down = false;
				m_pixels = 0;
			}
		}
	}
	if (m_right)
	{
		if (m_pixels <= 32 && m_moved == false)
		{
			m_blockPos.x++;
			m_pixels++;
		}
		else if (m_pixels > 32)
		{
			m_moved = true;
			m_framesSinceMove++;
		}
		if (m_moved && m_framesSinceMove >= 300)
		{
			m_blockPos.x--;
			if (m_framesSinceMove == 332)
			{
				m_moved = false;
				m_framesSinceMove = 0;
				m_right = false;
				m_pixels = 0;
			}
		}
	}
	if (m_left)
	{
		if (m_pixels <= 32)
		{
			m_blockPos.x--;
			m_pixels++;
		}
		else
		{
			m_moved = true;
			m_framesSinceMove++;
		}
		if (m_moved && m_framesSinceMove >= 300)
		{
			m_blockPos.x++;
			if (m_framesSinceMove == 332)
			{
				m_moved = false;
				m_framesSinceMove = 0;
				m_left = false;
				m_pixels = 0;
			}
		}
	}
	setPos();
}



