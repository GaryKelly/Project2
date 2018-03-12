#pragma once
#include <SFML\Graphics.hpp> 
#include "Globals.h"

class AwesomeSq
{
	int m_rowPlayer;
	int m_colPlayer;
	sf::RectangleShape m_playerShape = sf::RectangleShape(sf::Vector2f(BLOCK_HEIGHT, BLOCK_WIDTH));
	sf::Vector2f m_playerPos;
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	bool m_playerAlive;
	bool m_playerNorth;
	bool m_playerSouth;
	bool m_playerEast;
	bool m_playerWest;


public:
	int getRow();
	int getCol();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void setPos();
	void draw(sf::RenderWindow &t_window);

};