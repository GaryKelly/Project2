#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"

class maze
{
	sf::Texture m_squareTexture; //Maze cell Texture
	sf::Sprite m_squareSprite;   //Maze cell Sprite
	bool m_wall;			     //Bool for cell being a wall or empty
	bool m_moveableBlock;		 //Bool if cell is a block that can be moved
	sf::Vector2f m_blockPos;


public:
	bool getWall();			   //Returns true if wall is active
	void setWall();			   //sets wall bool true;
	void setWallFalse();	   //sets wall false
	bool moveable();		   //Returns true if block is moveable
	void setMoveable();		   //sets moveableBlock bool true
	void draw(sf::RenderWindow &t_window); //draws cells
	void setTexture();			//set text of block 
	void setSprite();		   //gives square the associated texture 
	void setPos(int t_row, int t_col); //sets position of the sprite
	bool getWallNorth();
	bool getWallSouth();
	bool getWallEast();
	bool getWallWest();
};

