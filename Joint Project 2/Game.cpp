// Name: Gary Kelly
// Login: C00207281
// Date: 16/04/18
// Approximate time taken: 50 hrs 
//---------------------------------------------------------------------------
// Project description Template
// ---------------------------------------------------------------------------
// Known Bugs: if block is moivin and level loaded it will movve
//			   player walk through moved block

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
	
	aGame.run();

	return 0;
}

/// <summary>
/// game constructor
/// </summary>
Game::Game() : window(sf::VideoMode(384, 384), "Project 2")
{
	gameMode = SPLASHSCREEN;
	//set messages
	m_font.loadFromFile("ASSETS/FONTS/font.otf");
	m_levelMessage.setFont(m_font);
	m_livesMessage.setFont(m_font);
	m_beesAliveMess.setFont(m_font);
	m_levelMessage.setFillColor(sf::Color::Black);
	m_livesMessage.setFillColor(sf::Color::Black);
	m_beesAliveMess.setFillColor(sf::Color::Black);
	m_levelMessage.setPosition(sf::Vector2f(150, 0));
	m_livesMessage.setPosition(sf::Vector2f(10, 0));
	m_beesAliveMess.setPosition(sf::Vector2f(100, 360));
	m_levelMessage.setCharacterSize(20);
	m_livesMessage.setCharacterSize(20);
	m_beesAliveMess.setCharacterSize(20);
	
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
	if (gameMode == SPLASHSCREEN)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			gameMode = LV1;
		}
	}
	if (gameMode == LV1)
	{
		currentLevel = 1;
		setLv1();
	}
	if (gameMode == LV2)
	{
		setLv2();
	}
	if (gameMode == LV3)
	{
		setLv3();
	}
	if (gameMode == GAMEPLAY) //updates the game world while levels are playing
	{
		keyboardInputs();
		playerMove();
		moveBox();
		moveEnemies();
		beesAlive = 0;
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (bees[i].getAlive())
			{
				beesAlive++;
			}
		}
		checkCollisions();
		checkLevelEnd();
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			checkOpenCells(bees[i].getEnemyRow(), bees[i].getEnemyCol(), i);
			bees[i].setBools();

		}

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLUMNS; j++)
			{
				myMaze[i][j].moveBlock();
			}
		}
	}
	if (gameMode == GAMEWIN || gameMode == GAMEOVER)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //restart game
		{
			gameMode = SPLASHSCREEN;
		}
	}


}
/// <summary>
/// draws game on screen
/// </summary>
void Game::draw()
{
	// Clear the screen and draw your game sprites
	window.clear(sf::Color::White);
	if (gameMode == GAMEPLAY) //draw gameplay
	{
		drawMaze();
		player.updateSprite();
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			bees[i].setTexture();
			bees[i].draw(window);
		}
		setMessages();
		window.draw(m_levelMessage);
		window.draw(m_livesMessage);
		window.draw(m_beesAliveMess);
		player.draw(window);
	}
	if (gameMode == SPLASHSCREEN) //draw splashscreen
	{
		screenText.loadFromFile("ASSETS/IMAGES/splashscreen.png");
		screenSprite.setTexture(screenText);
		screenSprite.setPosition(sf::Vector2f(0, 0));
		window.draw(screenSprite);
	}
	if (gameMode == GAMEOVER) //draw gameover
	{
		screenText.loadFromFile("ASSETS/IMAGES/gameover.png");
		screenSprite.setTexture(screenText);
		screenSprite.setPosition(sf::Vector2f(0, 0));
		window.draw(screenSprite);
	}
	if (gameMode == GAMEWIN) //draw game win
	{
		screenText.loadFromFile("ASSETS/IMAGES/gamewin.png");
		screenSprite.setTexture(screenText);
		screenSprite.setPosition(sf::Vector2f(0, 0));
		window.draw(screenSprite);
	}
	

	window.display();
}

//sets string for messages
void Game::setMessages()
{
	m_livesMessage.setString("Lives: " + std::to_string(player.getLives()));
	m_beesAliveMess.setString("Bees: " + std::to_string(beesAlive));
	m_levelMessage.setString("Level: " + std::to_string(currentLevel));
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
	if (noOfCells >= 3 && bees[t_bee].moving()==false)
	{
		changeEnemyDirection(t_row, t_col, t_bee);
	}
}
//function changes enemy direction by random number
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

//calls enemy move functions
void Game::moveEnemies()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (bees[i].getAlive())
		{
			
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



			if (bees[i].moving())
			{
				bees[i].move();
			}
			
		}
	}
	

	
}

//moves the box 
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

//checks end of levels
void Game::checkLevelEnd()
{
	if (beesAlive == 0)
	{
		if (currentLevel == 1)
		{
			gameMode = LV2;
		}
		if (currentLevel == 2)
		{
			gameMode = LV3;
		}
		if (currentLevel == 3)
		{
			gameMode = GAMEWIN;
		}
	}
	if (player.getLives() == 0)
	{
		gameMode = GAMEOVER;
	}
}

//collision detection
void Game::checkCollisions()
{

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (bees[i].getAlive())
		{
			if (player.getSprite().getGlobalBounds().intersects(bees[i].getSprite().getGlobalBounds())) //player/bees
			{
				player.loseLife();
				player.setBoolsFalse();
				resetLv(currentLevel, beesAlive);
			}
		}
		
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (myMaze[i][j].getMoving())
			{
				for (int k = 0; k < MAX_ENEMIES; k++)
				{
					if (bees[k].getAlive())
					{
						if (bees[k].getSprite().getGlobalBounds().intersects(myMaze[i][j].getSprite().getGlobalBounds())) //bees/moving box
						{
							bees[k].setDead();
						}
					}
				}
			}
		}
	}
	
}

//resets levels when hit
void Game::resetLv(int t_level, int t_bees)
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		bees[i].setDead();
	}
	for (int i = 0; i < t_bees; i++)
	{
		bees[i].setAlive();
	}
	//lv1
	if (t_level == 1)
	{
		
		player.setStart();
		if (t_bees == 3)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
			bees[1].setRowCol(10, 10);
			bees[1].setMoveLeft();
			bees[2].setRowCol(3, 6);
			bees[2].setMoveLeft();
		}
		else if (t_bees == 2)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
			bees[1].setRowCol(10, 10);
			bees[1].setMoveLeft();
		}
		else
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
		}

		
	}
	//end lv1
	//lv2
	if (t_level == 2)
	{
		player.setStart();
		if (t_bees == 1)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
		}
		if (t_bees == 2)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
			bees[1].setRowCol(10, 10);
			bees[1].setMoveLeft();
		}
		if (t_bees == 3)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
			bees[1].setRowCol(10, 10);
			bees[1].setMoveLeft();
			bees[2].setRowCol(6, 6);
			bees[2].setMoveLeft();
		}
		if (t_bees == 4)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
			bees[1].setRowCol(10, 10);
			bees[1].setMoveLeft();
			bees[2].setRowCol(6, 6);
			bees[2].setMoveLeft();
			bees[3].setRowCol(1, 10);
			bees[3].setMoveLeft();
		}
		
	}
	//end lv2
	//lv3
	if (t_level == 3)
	{
		player.setStart();
		if (t_bees == 1)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
		}
		if (t_bees == 2)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
			bees[1].setRowCol(10, 10);
			bees[1].setMoveLeft();
		}
		if (t_bees == 3)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
			bees[1].setRowCol(10, 10);
			bees[1].setMoveLeft();
			bees[2].setRowCol(6, 6);
			bees[2].setMoveLeft();
		}
		if (t_bees == 4)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
			bees[1].setRowCol(10, 10);
			bees[1].setMoveLeft();
			bees[2].setRowCol(6, 6);
			bees[2].setMoveLeft();
			bees[3].setRowCol(1, 10);
			bees[3].setMoveLeft();
		}
		if (t_bees == 5)
		{
			bees[0].setRowCol(10, 1);
			bees[0].setMoveUp();
			bees[1].setRowCol(10, 10);
			bees[1].setMoveLeft();
			bees[2].setRowCol(6, 6);
			bees[2].setMoveLeft();
			bees[3].setRowCol(1, 10);
			bees[3].setMoveLeft();
			bees[4].setRowCol(10, 6);
			bees[4].setMoveLeft();
		}

	}
	//end lv
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
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		bees[i].setRowCol(-1, -1);
		bees[i].setDead();
	}
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
	gameMode = GAMEPLAY;
}

//loads level two map/enemies
void Game::setLv2()
{
	for (int i = 0; i < lv2Enemies; i++)
	{
		bees[i].setAlive();
	}
	bees[0].setRowCol(10, 1);
	bees[0].setMoveUp();
	bees[1].setRowCol(10, 10);
	bees[1].setMoveLeft();
	bees[2].setRowCol(6, 6);
	bees[2].setMoveLeft();
	bees[3].setRowCol(1, 10);
	bees[3].setMoveLeft();
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (LEVEL_2[i][j] == 0)
			{
				myMaze[i][j].setWallFalse();
			}
			if (LEVEL_2[i][j] == 1)
			{
				myMaze[i][j].setWall();
			}
			if (LEVEL_2[i][j] == 2)
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
	gameMode = GAMEPLAY;
	currentLevel = 2;
}

//loads lv3 map/enemies
void Game::setLv3()
{
	for (int i = 0; i < lv3Enemies; i++)
	{
		bees[i].setAlive();
	}
	bees[0].setRowCol(10, 1);
	bees[0].setMoveUp();
	bees[1].setRowCol(10, 10);
	bees[1].setMoveLeft();
	bees[2].setRowCol(6, 6);
	bees[2].setMoveLeft();
	bees[3].setRowCol(1, 10);
	bees[3].setMoveLeft();
	bees[4].setRowCol(10, 6);
	bees[4].setMoveLeft();
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (LEVEL_3[i][j] == 0)
			{
				myMaze[i][j].setWallFalse();
			}
			if (LEVEL_3[i][j] == 1)
			{
				myMaze[i][j].setWall();
			}
			if (LEVEL_3[i][j] == 2)
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
	gameMode = GAMEPLAY;
	currentLevel = 3;
}




