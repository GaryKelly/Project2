// Name: Gary Kelly
// Login: C00207281
// Date: 
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description Template
// ---------------------------------------------------------------------------
// Known Bugs: i know 3
// beetle, bee, wasp

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

/// <summary>
/// game constructor
/// </summary>
Game::Game() : window(sf::VideoMode(384, 384), "Project 2")
// Default constructor
{
	player.setStart();
	setLv1();
}

/// <summary>
/// loads any game content
/// </summary>
void Game::LoadContent()
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


/// <summary>
/// calls functions to update game world
/// </summary>
void Game::update()
{
	keyboardInputs();
	playerMove();



}
/// <summary>
/// draws game on screen
/// </summary>
void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	drawMaze();
	player.updateSprite();
	player.draw(window);

	window.display();
}

/// <summary>
/// Takes player input from Direction Arrows
/// </summary>
void Game::keyboardInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)  ) //is up key pressed
	{
		if (!player.playerMovingUp() && !player.playerMovingDown() && !player.playerMovingLeft() && !player.playerMovingRight()) //is the player not moving
		{
			player.changeToUp();
			if (player.getRow() != 0) //is player not at screen Boundary
			{
				if (myMaze[(player.getRow() - 1)][player.getCol()].getWall() == false) //is the cell above player empty
				{
					player.keyUp();
				}
			}
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) //is down key pressed
	{
		if (!player.playerMovingUp() && !player.playerMovingDown() && !player.playerMovingLeft() && !player.playerMovingRight())//is the player not moving
		{
			player.changeToDown();
			if (player.getRow() < ROWS - 1) //is player not at screen Boundary
			{
				if (myMaze[(player.getRow() + 1)][player.getCol()].getWall() == false) //is the cell below player empty
				{
					player.keyDown();
				}
			}
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) //is left key pressed
	{
		if (!player.playerMovingUp() && !player.playerMovingDown() && !player.playerMovingLeft() && !player.playerMovingRight()) //is player not moving
		{
			player.changeToLeft();
			if (player.getCol() != 0) //is player not at screen boundary
			{
				if (myMaze[player.getRow()][(player.getCol() - 1)].getWall() == false) //is the cell to left of player empty
				{
					player.keyLeft();
				}
			}
		}
	
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) // is right key pressed
	{
		if (!player.playerMovingUp() && !player.playerMovingDown() && !player.playerMovingLeft() && !player.playerMovingRight()) //is player not moving
		{
			player.changeToRight();
			if (player.getCol() < COLUMNS - 1) //is player not at boundary 
			{
				if (myMaze[player.getRow()][(player.getCol() + 1)].getWall() == false) //is cell to right of player empty
				{
					player.keyRight();
				}
			}
		}
	
	}
}

/// <summary>
/// function calss player move functions
/// </summary>
void Game::playerMove()
{
	if (player.playerMovingUp()) //is player moving up
	{
		player.moveUp();
	}
	else if (player.playerMovingDown()) //is player moving down
	{
		player.moveDown();
	}
	else if (player.playerMovingRight()) //is player moving right
	{
		player.moveRight();
	}
	else if (player.playerMovingLeft()) //is player moving left
	{
		player.moveLeft();
	}
}

/// <summary>
/// draws the maze on screen
/// </summary>
void Game::drawMaze()
{
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLUMNS; col++)
		{
			myMaze[row][col].draw(window);
		}
	}
}


/// <summary>
/// function calls others to construct maze at start of program
/// </summary>
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

	//calls pos and texture for all cells in maze
	for ( row = 0; row < ROWS; row++)
	{
		for ( col = 0; col < COLUMNS; col++)
		{
			myMaze[row][col].setPos(row, col);
			myMaze[row][col].setTexture();
		}
	}
}

//sets row 0
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

//sets row 1
void Game::row1()
{
	for ( col = 0,  row = 1; col < COLUMNS; col++)
	{
		if (col == 0 || col == 9 )
		{
			myMaze[row][col].setWallFalse();
		}
		
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

//ses row 2
void Game::row2()
{
	for ( col = 0, row = 2; col < COLUMNS; col++)
	{
		if (col == 0 || col == 9 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

//sets row 3
void Game::row3()
{
	for ( col = 0, row = 3; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || col == 5 || col == 9 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

//sets row 4
void Game::row4()
{
	for ( col = 0, row = 4; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || (col >= 5 && col <= 11) )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}		
	}
}

//sets row 5
void Game::row5()
{
	for ( col = 0,  row = 5; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || col == 5 || col == 7 || col == 9 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

//sets row 6
void Game::row6()
{
	for ( col = 0,  row = 6; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || col == 5 || col == 9 || col == 11 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

//sets row 7
void Game::row7()
{
	for ( col = 0,  row = 7; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || col == 5 || col == 9 || col == 11 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

//sets row 8
void Game::row8()
{
	for ( col = 0,  row = 8; col < COLUMNS; col++)
	{
		if (col == 0 || col == 2 || (col >= 5 && col <= 9) )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

//sets row 9
void Game::row9()
{
	for ( col = 0,  row = 9; col < COLUMNS; col++)
	{
		if ((col >= 0 && col <= 5) || col == 10 || col == 11 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

//sets row 10
void Game::row10()
{
	for ( col = 0,  row = 10; col < COLUMNS; col++)
	{
		if ( (col >= 1 && col <= 8) || col == 10 || col == 11 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}

//sets row 11
void Game::row11()
{
	for ( col = 0,  row = 11; col < COLUMNS; col++)
	{
		if (col == 1 || col == 5 || col == 10 || col == 11 )
		{
			myMaze[row][col].setWallFalse();
		}
		else
		{
			myMaze[row][col].setWall();
		}
	}
}



