#pragma once
#include <SFML\Graphics.hpp> 
#include "Globals.h"

class AwesomeSq
{
	int m_rowPlayer= 0;
	int m_colPlayer= 0;
	sf::RectangleShape m_playerShape = sf::RectangleShape(sf::Vector2f(BLOCK_HEIGHT, BLOCK_WIDTH));
	sf::Vector2f m_playerPos;
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	bool m_playerAlive;
	bool m_playerNorth;
	bool m_playerSouth;
	bool m_playerEast;
	bool m_playerWest;
	bool m_playerMovingUp = false;
	bool m_playerMovingDown = false;
	bool m_playerMovingRight = false;
	bool m_playerMovingLeft = false;

public:
	AwesomeSq();
	int getRow();
	int getCol();
	void keyUp();
	void keyDown();
	void keyLeft();
	void keyRight();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void setPos();
	void draw(sf::RenderWindow &t_window);
	void setStart();
	bool playerMovingRight();
	bool playerMovingLeft();
	bool playerMovingUp();
	bool playerMovingDown();

};