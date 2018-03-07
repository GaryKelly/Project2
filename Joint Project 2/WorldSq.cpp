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

void maze::setTextureWall()
{
	m_squareTexture.loadFromFile("ASSETS/IMAGES/wall.png");
}

void maze::setTextureBlock()
{
	m_squareTexture.loadFromFile("ASSETS/IMAGES/moveBlock");
}

void maze::setTextureFloor()
{
	m_squareTexture.loadFromFile("ASSETS/IMAGES/floor.png")
}

void maze::setSprite()
{
	m_squareSprite.setTexture(m_squareTexture);
}
