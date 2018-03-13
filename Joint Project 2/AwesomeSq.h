#pragma once
#include <SFML\Graphics.hpp> 
#include "Globals.h"

class AwesomeSq
{
	int m_rowPlayer= 0;
	int m_colPlayer= 0;
	int m_halfMovePix = 0;
	
	sf::Vector2f m_playerPos;
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	sf::Image m_spriteSheet;
	sf::IntRect m_spriteSheetRect;
	int m_sheetNoRow = 8;
	int m_sheetNoCol = 12;
	bool m_playerAlive;
	bool m_playerNorth;
	bool m_playerSouth;
	bool m_playerEast;
	bool m_playerWest;
	bool m_playerMovingUp = false;
	bool m_playerMovingDown = false;
	bool m_playerMovingRight = false;
	bool m_playerMovingLeft = false;
	bool m_halfMove = false;

public:
	AwesomeSq();
	void updateSprite();
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