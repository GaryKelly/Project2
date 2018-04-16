// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <fstream>
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function


#include "AwesomeSq.h"   // include AwesomeSq header file
#include "EvilSq.h"   // include EvilSq header file
#include "WorldSq.h" //Include worldSq header
#include "Globals.h" //include globals

class Game
{
	cell myMaze[ROWS][COLUMNS]; //2D array for maze
	AwesomeSq player;			//player object
	EvilSq bees[MAX_ENEMIES];   //1D Array of enemy objects
	sf::RenderWindow window;    //render window
	bool keyPressed = false;
	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;
	sf::Texture screenText;
	sf::Sprite screenSprite;
	enum GameMode 
	{
		SPLASHSCREEN,
		LV1,
		LV2,
		LV3,
		GAMEPLAY,
		GAMEOVER,
		GAMEWIN
	};
	GameMode gameMode;
	
	
	int level;					//Variable that holds the current level
	int col;
	int row;
	int lv1Enemies = 3;
	int lv2Enemies = 4;
	int lv3Enemies = 5;
	int beesAlive;
	int currentLevel;
public:
	sf::Font m_font;  // font for writing text
	sf::Text m_livesMessage;  
	sf::Text m_levelMessage;
	sf::Text m_beesAliveMess;

public:	  // declaration of member functions	
	Game();  // default constructor
	
	void	run();		   //run game content
	void	update();	   //update game
	void	draw();		   //draw game 
	void	setMessages();
	void    keyboardInputs(); //key input function
	void    playerMove(); //player move function
	void	checkOpenCells(int t_row, int t_col, int t_bee); //checks the number of open cells around enemy position
	void	changeEnemyDirection(int t_row, int t_col, int t_bee); //function will change enemy direction  
	void	moveEnemies(); //function calls enemy 
	void	moveBox();
	void	checkLevelEnd();
	void	checkCollisions();
	void	resetLv(int t_level, int t_bees);
	
	void	setLv1();			   //Sets maze up for level 1
	void	setLv2();
	void	setLv3();
	
	void	drawMaze();   //darw maze (for loops)
	
};

