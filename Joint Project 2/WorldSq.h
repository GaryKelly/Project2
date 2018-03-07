#pragma once
#include <SFML/Graphics.hpp>


class maze
{
	sf::Texture m_squareTexture; //Maze cell Texture
	sf::Sprite m_squareSprite;   //Maze cell Sprite
	bool m_wall;			     //Bool for cell being a wall or empty
	bool m_moveableBlock;		 //Bool if cell is a block that can be moved


public:
	bool getWall();			   //Returns true if wall is active
	void setWall();			   //sets wall bool true;
	void setWallFalse();	   //sets wall false
	bool moveable();		   //Returns true if block is moveable
	void setMoveable();		   //sets moveableBlock bool true
	void draw(sf::RenderWindow &t_window); //draws cells
	void setTextureWall();     //sets texture if square is a wall
	void setTextureBlock();    //sets texture if square is a block
	void setTextureFloor();    //sets texture if square is empty 
	void setSprite();		   //gives square the associated texture 
};

