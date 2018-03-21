// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
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
	int level;					//Variable that holds the current level
	int col;
	int row;
public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game();  // default constructor
	void	LoadContent(); //load game content
	void	run();		   //run game content
	void	update();	   //update game
	void	draw();		   //draw game 
	void    keyboardInputs(); //key input function
	void    playerMove(); //player move function
	void	checkOpenCells(int t_row, int t_col); //checks the number of open cells around enemy position
	void	changeEnemyDirection(int t_row, int t_col); //function will change enemy direction  
	void	moveEnemies(); //function calls enemy 
	
	void	setLv1();			   //Sets maze up for level 1
	//sets rows
	void    row1();
	void    row2();
	void    row3();
	void    row4();
	void    row5();
	void    row6();
	void    row7();
	void    row8();
	void    row9();
	void    row10();
	void    row11();
	void    row0();
	void	drawMaze();   //darw maze (for loops)
	
};

