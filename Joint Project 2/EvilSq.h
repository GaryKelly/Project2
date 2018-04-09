#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h" //include globals header

class EvilSq
{
	int m_enemyRow{};				//row in which enemy is in
	int m_enemyColumn{};			//column in which enemy is in
	int m_enemyDistInCell;			//
	sf::Image m_enemySpriteSheet;   //image for enemy sprite sheet
	sf::Sprite m_enemySprite;		//enemy sprite
	sf::Texture m_enemyTexture;		//enemy texture
	sf::Vector2f m_enemyPos;		//enemy position
	double m_enemySpeed;			//speed of enemy
	bool m_enemyAlive;				//bool for if enemy is alive
	//direction bools
	bool m_enemyMovingUp;
	bool m_enemyMovingDown;
	bool m_enemyMovingLeft;
	bool m_enemyMovingRight;
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
	void setRowCol(int t_row, int t_col);
	void setPos();


	void setTexture();				//sets texture of enemy
	bool getMoveUp();
	bool getMoveDown();
	bool getMoveLeft();
	bool getMoveRight();
	void setMoveUp();
	void setMoveDown();
	void setMoveLeft();
	void setMoveRight();
	bool getAlive();
	void setAlive();
	void draw(sf::RenderWindow &t_window);
};
