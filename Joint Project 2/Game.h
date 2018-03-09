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
	maze myMaze[ROWS][COLUMNS]; //2D array for maze
	sf::RenderWindow window;    //render window
	int level;					//Variable that holds the current level
	int col;
	int row;
public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game();  // default constructor
	void	LoadContent();
	void	run();
	void	update();
	void	draw();
	
	void	setLv1();			   //Sets maze up for level 1
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
	void    row12();
	void    row13();
	void    row14();
	void    row0();
	void	drawMaze();
};

