#include "WorldSq.h"

bool maze::getWall()
{
	return m_wall;
}

void maze::setWall()
{
	m_wall = true;
}

void maze::setWallFalse()
{
	m_wall = false;
}

bool maze::moveable()
{
	return m_moveableBlock;
}

void maze::setMoveable()
{
	m_moveableBlock = true;
}

void maze::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_squareSprite);
}

void maze::setTexture()
{
	if (m_wall == true)
	{
		m_squareTexture.loadFromFile("ASSETS/IMAGES/wall.png");
	}
	else if (m_wall == false)
	{
		m_squareTexture.loadFromFile("ASSETS/IMAGES/floor.png");
	}
	

	
	setSprite();
}



void maze::setSprite()
{
	m_squareSprite.setTexture(m_squareTexture);
}

void maze::setPos(int t_row, int t_col)
{
	m_blockPos.x = BLOCK_WIDTH * t_col;
	m_blockPos.y = BLOCK_HEIGHT * t_row;
	m_squareSprite.setPosition(m_blockPos);

}

