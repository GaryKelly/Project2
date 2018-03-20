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

void EvilSq::setSprite()
{
}


