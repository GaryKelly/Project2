// Name: 
// Login: 
// Date: 
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description Template
// ---------------------------------------------------------------------------
// Known Bugs:
// List your bugs here

//////////////////////////////////////////////////////////// 
// Headers for SFML projects
// include correct library file for release and debug versions
// include iostream for console window output
// include 
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file


int main()
{
	Game aGame;
	aGame.LoadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(480, 480), "Project 2")
// Default constructor
{
	
	setLv1();
}


void Game::LoadContent()
// load the font file & set up message
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}
	
	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen
}


void Game::run()
{
	srand(time(nullptr)); // set the seed once
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{

			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}



void Game::update()
// This function takes the keyboard input and updates the game world
{

	// update any game variables here ...

}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	drawMaze();

	window.display();
}

void Game::setLv1()
{
	row0();
	row1();
	row2();
	row3();
	row4();
	row5();
	row6();
	row7();
	row8();
	row9();
	row10();
	row11();
	row12();
	row13();
	row14();
	for ( row = 0; row < ROWS; row++)
	{
		for ( col = 0; col < COLUMNS; col++)
		{
			myMaze[row][col].setPos(row, col);
			myMaze[row][col].setTexture();
		}
	}
}


void Game::row0()
{
	row = 0;
	for ( col = 0; col < COLUMNS; col++)
	{
		if (col != 1)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}




void Game::row1()
{
	for ( col = 0,  row = 1; col < COLUMNS; col++)
	{
		if (col == 0 || col == 9 || col == 14)
		{
			myMaze[row][col].setWallFalse();
		}
		
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row2()
{
	for ( col = 0, row = 2; col < COLUMNS; col++)
	{
		if (col == 0 || col == 9 || col == 14)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row3()
{
	for ( col = 0, row = 3; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || col == 5 || col == 9 || col == 12 || col == 14)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row4()
{
	for ( col = 0, row = 4; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || (col >= 5 && col <= 12) || col == 14 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}		
	}
}

void Game::row5()
{
	for ( col = 0,  row = 5; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || col == 5 || col == 7 || col == 9 || col == 12 || col == 14)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row6()
{
	for ( col = 0,  row = 6; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || col == 5 || col == 9 || (col >= 11 && col <= 14))
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row7()
{
	for ( col = 0,  row = 7; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || col == 5 || col == 9 || col == 11 || col == 12 || col == 14)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row8()
{
	for ( col = 0,  row = 8; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || (col >= 5 && col <= 9) || col == 14)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row9()
{
	for ( col = 0,  row = 9; col < COLUMNS; col++)
	{
		if ((col >= 0 && col <= 5) || col == 10 || col == 11 || col == 14)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row10()
{
	for ( col = 0,  row = 10; col < COLUMNS; col++)
	{
		if ( (col >= 1 && col <= 8) || col == 10 || col == 11 || col == 14)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row11()
{
	for ( col = 0,  row = 11; col < COLUMNS; col++)
	{
		if (col == 1 || col == 5 || col == 10 || col == 11 || col == 14)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row12()
{
	for ( col = 0,  row = 12; col < COLUMNS; col++)
	{
		if (col != 0 || col != 2)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row13()
{
	for ( col = 0, row = 13; col < COLUMNS; col++)
	{
		if ((col >= 1 && col <= 5)||  col == 12 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::row14()
{
	for ( col = 0,  row = 14; col < COLUMNS; col++)
	{
		if (col >= 5)
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

void Game::drawMaze()
{
	for ( row = 0; row < ROWS; row++)
	{
		for ( col = 0; col < COLUMNS; col++)
		{
			myMaze[row][col].draw(window);
		}
	}
}