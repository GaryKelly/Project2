#pragma once


const int ROWS = 12;		 //no of rows in maze
const int COLUMNS = 12;		 //no of columns in maze
const int BLOCK_HEIGHT = 32; //no of pixels in height of all sprites
const int BLOCK_WIDTH = 32;  //no of pixels in width of all sprites 
const int MAX_ENEMIES = 5;	 //Max no of enemies alive

const int LEVEL_1[ROWS][COLUMNS]{ 1,1,1,1,1,1,1,1,1,1,1,1, //ROW1
								  1,0,0,0,0,0,0,0,0,0,0,1, //ROW2
								  1,0,2,0,1,1,1,1,2,1,0,1, //ROW3
								  1,0,1,0,0,0,0,0,0,1,0,1, //ROW4
								  1,0,1,1,2,1,1,1,0,1,0,1, //R0W5
								  1,0,1,0,0,0,0,0,0,1,0,1, //ROW6
								  1,0,1,0,1,1,2,1,1,1,0,1, //ROW7
								  1,0,1,0,0,0,0,0,0,1,0,1, //ROW8
								  1,0,1,1,1,1,1,2,0,1,0,1, //ROW9
							      1,0,1,0,0,0,0,0,0,2,0,1, //ROW10
								  1,0,0,0,1,1,1,1,0,0,0,1, //ROW11
								  1,1,1,1,1,1,1,1,1,1,1,1 }; //ROW12
const int LEVEL_2[ROWS][COLUMNS]{ 1,1,1,1,1,1,1,1,1,1,1,1, //ROW1
								  1,0,0,0,0,0,0,0,0,0,0,1, //ROW2
								  1,0,1,0,0,0,0,0,0,2,0,1, //ROW3
								  1,0,0,2,0,0,0,0,1,0,0,1, //ROW4
								  1,0,0,0,1,0,0,1,0,0,0,1, //R0W5
								  1,0,0,0,0,0,0,0,0,0,0,1, //ROW6
								  1,0,0,0,2,0,0,1,0,0,0,1, //ROW7
								  1,0,0,1,0,0,0,0,2,0,0,1, //ROW8
								  1,0,2,0,0,0,0,0,0,1,0,1, //ROW9
								  1,2,0,0,0,0,0,0,0,0,1,1, //ROW10
								  1,0,0,0,0,0,0,0,0,0,0,1, //ROW11
							      1,1,1,1,1,1,1,1,1,1,1,1 }; //ROW12
const int LEVEL_3[ROWS][COLUMNS]{ 1,1,1,1,1,1,1,1,1,1,1,1, //ROW1
							      1,0,0,0,0,0,0,0,0,0,0,1, //ROW2
								  1,0,0,0,1,0,0,2,0,0,0,1, //ROW3
							      1,0,0,2,0,0,0,0,1,0,0,1, //ROW4
								  1,0,0,0,1,0,0,1,0,0,0,1, //R0W5
								  1,0,1,0,2,0,0,0,1,0,2,1, //ROW6
						          1,2,0,1,0,0,0,1,0,1,0,1, //ROW7
							      1,0,0,1,0,0,0,0,2,0,0,1, //ROW8
								  1,0,0,1,0,0,0,0,1,0,0,1, //ROW9
								  1,0,1,0,0,0,0,0,0,0,0,1, //ROW10
								  1,0,0,0,2,0,0,1,0,0,0,1, //ROW11
								  1,1,1,1,1,1,1,1,1,1,1,1 }; //ROW12
		
			
			
