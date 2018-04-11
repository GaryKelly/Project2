#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"

class cell
{
	sf::Texture m_squareTexture; //Maze cell Texture
	sf::Sprite m_squareSprite;   //Maze cell Sprite
	bool m_wall;			     //Bool for cell being a wall or empty
	bool m_moveableBlock = false;	//Bool if cell is a block that can be moved
	bool m_left = false;
	bool m_right = false;
	bool m_up = false;
	bool m_down = false;
	bool m_moved = false;
	int m_pixels = 0;
	int m_framesSinceMove = 0;

	sf::Vector2f m_blockPos;	 //Position of cell
	void setPos();

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
	sf::Vector2f getPos();
	void setUp();
	void setDown();
	void setRight();
	void setLeft();
	void moveBlock();
	

};

