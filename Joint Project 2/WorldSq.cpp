#include "WorldSq.h"

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



