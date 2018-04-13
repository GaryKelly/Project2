#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h" //include globals header

class EvilSq
{
	int m_enemyRow{};				//row in which enemy is in
	int m_enemyColumn{};			//column in which enemy is in
	int m_enemyDistInCell = 0;			
	sf::Image m_enemySpriteSheet;   //image for enemy sprite sheet
	sf::Sprite m_enemySprite;		//enemy sprite
	sf::Texture m_enemyTexture;		//enemy texture
	sf::Vector2f m_enemyPos;		//enemy position
				
	bool m_enemyAlive = false;				//bool for if enemy is alive
	//direction bools
	bool m_enemyMovingUp = false;
	bool m_enemyMovingDown = false;
	bool m_enemyMovingLeft = false;
	bool m_enemyMovingRight = false;
	bool m_moving = false;
	bool m_up = false;
	bool m_down = false;
	bool m_left = false;
	bool m_right = false; 
	//sprite selection bools
	bool m_sprite1;
	bool m_sprite2;
	
	
	void setSprite();				//sets enemy sprite



public:
	EvilSq();
	int getEnemyRow();				//function to get enemy row
	int getEnemyCol();				//function to get enemy col
	//enemy move functions
	void move();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	bool moving();
	void setRowCol(int t_row, int t_col);
	void setPos();
	sf::Vector2f getPos();


	void setTexture();				//sets texture of enemy
	bool getMoveUp();
	bool getMoveDown();
	bool getMoveLeft();
	bool getMoveRight();
	void setMoveUp();
	void setMoveDown();
	void setMoveLeft();
	void setMoveRight();
	void setBools();
	bool getAlive();
	void setAlive();
	void setDead();
	void draw(sf::RenderWindow &t_window);
	sf::Sprite getSprite();
};
