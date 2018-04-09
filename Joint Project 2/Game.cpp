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
	moveBox();
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (bees[i].getAlive())
		{
			bees[i].move();
			checkOpenCells(bees[i].getEnemyRow(), bees[i].getEnemyCol(), i);
		}
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			myMaze[i][j].moveBlock();
		}
	}


}
/// <summary>
/// draws game on screen
/// </summary>
void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear(sf::Color::White);

	drawMaze();
	player.updateSprite();
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (bees[i].getAlive())
		{
			bees[i].setTexture();
			bees[i].draw(window);
		}
	}
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
		if (!player.isPlayerMoving() && keyPressed == false ) //is the player not moving
		{
			player.changeToUp();
			if (player.getRow() != 0) //is player not at screen Boundary
			{
				
				if (myMaze[(player.getRow() - 1)][player.getCol()].getWall() == false && myMaze[(player.getRow() - 1)][player.getCol()].moveable() == false) //is the cell above player empty
				{
					player.keyUp();
					keyPressed = true;
				}
			}
		}
		
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) //is down key pressed
	{
		if (!player.isPlayerMoving() && keyPressed == false)//is the player not moving
		{
			player.changeToDown();
			if (player.getRow() < ROWS - 1) //is player not at screen Boundary
			{
				if (myMaze[(player.getRow() + 1)][player.getCol()].getWall() == false && myMaze[(player.getRow() + 1)][player.getCol()].moveable() == false) //is the cell below player empty
				{
					player.keyDown();
					keyPressed = true;
					
				}
			}
		}
		
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && keyPressed == false ) //is left key pressed
	{
		if (!player.isPlayerMoving()) //is player not moving
		{
			player.changeToLeft();
			if (player.getCol() != 0) //is player not at screen boundary
			{
				if (myMaze[player.getRow()][(player.getCol() - 1)].getWall() == false && myMaze[player.getRow()][(player.getCol() - 1)].moveable() == false) //is the cell to left of player empty
				{
					player.keyLeft();
					keyPressed = true;
					
				}
			}
		}
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) // is right key pressed
	{
		if (!player.isPlayerMoving() && keyPressed == false) //is player not moving
		{
			player.changeToRight();
			if (player.getCol() < COLUMNS - 1) //is player not at boundary 
			{
				if (myMaze[player.getRow()][(player.getCol() + 1)].getWall() == false && myMaze[player.getRow()][(player.getCol() + 1)].moveable()==false) //is cell to right of player empty
				{
					player.keyRight();
					keyPressed = true;
					
				}
			}
		}
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (player.isPlayerMoving() == false)
		{
			if (player.playerUp())
			{
				if (myMaze[player.getRow()-1][player.getCol()].moveable() && myMaze[player.getRow() - 2][player.getCol()].getWall() == false)
				{
					if (!up)
					{
						up = true;
						row = player.getRow() - 1;
						col = player.getCol();
					}
				
				}
			}
			else if (player.playerDown())
			{
				if (myMaze[player.getRow() + 1][player.getCol()].moveable() && myMaze[player.getRow() + 2][player.getCol()].getWall() == false)
				{
					if (!down)
					{
						down = true;
						row = player.getRow() + 1;
						col = player.getCol();
					}
					
				}
			}
			else if (player.playerLeft())
			{
				if (myMaze[player.getRow()][player.getCol()-1].moveable() && myMaze[player.getRow()][player.getCol() - 2].getWall()==false)
				{
					if (!left)
					{
						left = true;
						row = player.getRow();
						col = player.getCol() - 1;
					}
					
				}
			}
			else if (player.playerRight())
			{
				if (myMaze[player.getRow()][player.getCol() + 1].moveable() && myMaze[player.getRow()][player.getCol() + 2].getWall() ==false)
				{
					if (!right)
					{
						right = true;
						row = player.getRow();
						col = player.getCol() + 1;
					}
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
	if (!player.isPlayerMoving())
	{
		keyPressed = false;
	}
}

/// <summary>
/// checks the number of open cells around an enemy 
/// used to change enemies direction if 3+ cells are free
/// </summary>
/// <param name="t_row"></param>
/// <param name="t_col"></param>
void Game::checkOpenCells(int t_row, int t_col, int t_bee)
{
	int noOfCells{ 0 };
	
	
	if (t_row != 0)//Checks cell above enemy
	{
		if (myMaze[t_row-1][t_col].getWall() == false)
		{
			noOfCells++;
		}
	}
	if (t_row != ROWS - 1)//checks cell below enemy
	{
		if (myMaze[t_row + 1][t_col].getWall()==false)
		{
			noOfCells++;
		}
	}
	if (t_col != 0)
	{
		if (myMaze[t_row][t_col-1].getWall() == false)
		{
			noOfCells++;
		}
	}
	if (t_col != COLUMNS - 1)
	{
		if (myMaze[t_row][t_col + 1].getWall() == false)
		{
			noOfCells++;
		}
	}
	if (noOfCells >= 3)
	{
		changeEnemyDirection(t_row, t_col, t_bee);
	}
}

void Game::changeEnemyDirection(int t_row, int t_col, int t_bee)
{
	int changeDirRandVal{ 0 };
	bool directionPicked = false;
	
	while (!directionPicked)
	{
		changeDirRandVal = (rand() % 4) + 1;

		if (changeDirRandVal == 1)
		{
			if (myMaze[t_row - 1][t_col].getWall() == false)
			{
				directionPicked = true;
				bees[t_bee].setMoveUp();
			}
		}
		else if (changeDirRandVal == 2)
		{
			if (myMaze[t_row + 1][t_col].getWall() == false)
			{
				directionPicked = true;
				bees[t_bee].setMoveDown();
			}
		}
		else if (changeDirRandVal == 3)
		{
			if (myMaze[t_row][t_col + 1].getWall() == false)
			{
				directionPicked = true;
				bees[t_bee].setMoveRight();
			}
		}
		else if (changeDirRandVal == 4)
		{
			if (myMaze[t_row][t_col-1].getWall() == false)
			{
				directionPicked = true;
				bees[t_bee].setMoveLeft();
			}
		}
	}
	

}

void Game::moveEnemies()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (bees[i].getAlive())
		{
			checkOpenCells(bees[i].getEnemyRow(), bees[i].getEnemyCol(), i);
			if (bees[i].getMoveUp())
			{
				if (myMaze[bees[i].getEnemyRow() - 1][bees[i].getEnemyCol()].getWall())
				{
					changeEnemyDirection(bees[i].getEnemyRow(), bees[i].getEnemyCol(), i);
				}
			}
			if (bees[i].getMoveDown())
			{
				if (myMaze[bees[i].getEnemyRow() + 1][bees[i].getEnemyCol()].getWall())
				{
					changeEnemyDirection(bees[i].getEnemyRow(), bees[i].getEnemyCol(), i);
				}
			}
			if (bees[i].getMoveRight())
			{
				if (myMaze[bees[i].getEnemyRow()][bees[i].getEnemyCol()+1].getWall())
				{
					changeEnemyDirection(bees[i].getEnemyRow(), bees[i].getEnemyCol(), i);
				}
			}
			if (bees[i].getMoveLeft())
			{
				if (myMaze[bees[i].getEnemyRow()][bees[i].getEnemyCol()-1].getWall())
				{
					changeEnemyDirection(bees[i].getEnemyRow(), bees[i].getEnemyCol(), i);
				}
			}
			
			bees[i].move();
		}
	}
	

	
}

void Game::moveBox()
{
	if (up)
	{
		myMaze[row][col].setUp();
		up = false;
	}
	if (down)
	{
		myMaze[row][col].setDown();
		down = false;
	}
	if (right)
	{
		myMaze[row][col].setRight();
		right = false;
	}
	if (left)
	{
		myMaze[row][col].setLeft();
		left = false;
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
			if (myMaze[row][col].getWall() == false && myMaze[row][col].moveable() == false)
			{
				myMaze[row][col].draw(window);
			}
		}
	}
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLUMNS; col++)
		{
			if (myMaze[row][col].getWall() == true)
			{
				myMaze[row][col].draw(window);
			}
		}
	}
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLUMNS; col++)
		{
			if ( myMaze[row][col].moveable() == true)
			{
				myMaze[row][col].draw(window);
			}
		}
	}
}


/// <summary>
/// function calls others to construct maze at start of program
/// </summary>
void Game::setLv1()
{

	for (int i = 0; i < lv1Enemies; i++)
	{
		bees[i].setAlive();
	}
	bees[0].setRowCol(10, 1);
	bees[0].setMoveUp();
	bees[1].setRowCol(10, 10);
	bees[1].setMoveLeft();
	bees[2].setRowCol(3, 6);
	bees[2].setMoveLeft();
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (LEVEL_1[i][j] == 0)
			{
				myMaze[i][j].setWallFalse();
			}
			if (LEVEL_1[i][j] == 1)
			{
				myMaze[i][j].setWall();
			}
			if (LEVEL_1[i][j] == 2)
			{
				myMaze[i][j].setMoveable();
			}
		}
	}

	//calls pos and texture for all cells in maze
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLUMNS; col++)
		{
			myMaze[row][col].setPos(row, col);
			myMaze[row][col].setTexture();
		}
	}

	player.setStart();
}




