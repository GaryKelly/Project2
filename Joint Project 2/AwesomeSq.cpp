// AwesomeSq function definitions here

#include "AwesomeSq.h"

int AwesomeSq::getRow()
{
	return m_rowPlayer;
}

int AwesomeSq::getCol()
{
	return m_colPlayer;
}

void AwesomeSq::moveUp()
{
	m_rowPlayer--;
	m_playerPos.y = m_rowPlayer * BLOCK_HEIGHT;
	setPos();
}

void AwesomeSq::moveDown()
{
	m_rowPlayer++;
	m_playerPos.y = m_rowPlayer * BLOCK_HEIGHT;
	setPos();
}

void AwesomeSq::moveLeft()
{
	m_colPlayer--;
	m_playerPos.x = m_colPlayer * BLOCK_WIDTH;
	setPos();

}

void AwesomeSq::moveRight()
{
	m_colPlayer++;
	m_playerPos.x = m_colPlayer * BLOCK_WIDTH;
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
