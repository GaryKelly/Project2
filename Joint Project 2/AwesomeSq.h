#pragma once
#include <SFML\Graphics.hpp> 
#include "Globals.h"

class AwesomeSq
{
	int m_rowPlayer= 0;               //player row
	int m_colPlayer= 0;				  //player column
	int m_halfMovePix = 0;			  //variable for half movement through cell
	
	sf::Vector2f m_playerPos;		  //player position
	sf::Texture m_playerTexture;	  //player texture
	sf::Sprite m_playerSprite;		  //player sprite
	sf::Image m_spriteSheet;		  //player spritesheet image 

	bool m_playerAlive;				  //bool for player alive
	//direction bools
	bool m_playerNorth;				  
	bool m_playerSouth;
	bool m_playerEast;
	bool m_playerWest;
	//movement bools
	bool m_playerMovingUp = false;
	bool m_playerMovingDown = false;
	bool m_playerMovingRight = false;
	bool m_playerMovingLeft = false;
	bool m_halfMove = false;		 //this bool is used for changing sprite "animation"
	bool m_moving = false;
public:
	AwesomeSq();					 //contructor
	void updateSprite();			 //updates the texture/sprite
	int getRow();					 //returns players row in maze
	int getCol();					 //returns player column in maze
	//key press functions
	void keyUp();
	void keyDown();
	void keyLeft();
	void keyRight();
	//change direction functions
	void changeToUp();
	void changeToDown();
	void changeToRight();
	void changeToLeft();
	//movement functions
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void setPos();					       //set player position
	void draw(sf::RenderWindow &t_window); //draw player
	void setStart();					   //set start pos of player

	//bool returns for player moving in direction
	bool playerMovingRight();
	bool playerMovingLeft();
	bool playerMovingUp();
	bool playerMovingDown();
	bool isPlayerMoving();
	//bool returns for what direction the player is facing
	bool playerUp();
	bool playerDown();
	bool playerLeft();
	bool playerRight();


};