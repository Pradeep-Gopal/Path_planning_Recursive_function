/**
* @file main.cpp
* @author Pradeep Gopal <pradeepg@terpmail.umd.edu>
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
* This project is used to navigate a Robot from a Start coordinate to a Goal coordinate
*/

// Including all the needed libraries
#include <iostream>
#include <array>

/**
 * @brief A function which recursively finds the path for the robot from the start coordinate to the goal coordinate
 * @author Pradeep Gopal
 * @param x coordinate of the Start point
 * @param y coordinate of the Start point
 * @return Maze with path from the Start point to the Goal point
 */
bool FindPath(int x, int y);

/**
 * @brief A function which prints the maze
 * @author Pradeep Gopal
 * @param char The maze to be printed
 */
void PrintMaze(const std::array<std::array<char, 6>, 6> &maze);

// Initialization of the variables
int a,b,c,d;
std::array<std::array<char, 6>, 6> maze = {{{'#','.','.','.','#','#'}, {'.','.', '#','.','.','.'}, {'#','.', '#', '#','.', '#'} , {'#', '.', '#', '#','.', '#'},{'.', '.','.', '#', '.', '#'},{'.', '#', '#', '#', '#', '#'}}};
 

// Function which prints the maze 
void PrintMaze(const std::array<std::array<char, 6>, 6> &maze)
{
	for (int i = maze.size() - 1; i >= 0; i--) 
   {  
	   for (int j = 0; j < maze[i].size(); j++) 
			std::cout << " " << maze[i][j];           
		std::cout << std::endl;
   }
}

//Function to find the path from start node to the Goal node
bool FindPath(int x, int y)
{
	if ((x > 5) || (y > 5) || (x < 0) || (y<0)) //Outside maze
	{
		return false;
	}
	if (maze[x][y] == 'G') //Goal Reached
	{
		return true;
	}
	if (maze[x][y] == '#') //obstacle
	{
		return false;
	}
	if (maze[x][y] == '+')
	{
		return false;
	}
	
	maze[x][y] = '+';

	if (FindPath(x+1, y) == true) //North
	{
		return true;
	}
	if (FindPath(x, y+1) == true) //East
	{
		return true;
	}
	if (FindPath(x-1, y) == true) //South
	{
		return true;
	}
	if (FindPath(x, y-1) == true) //West
	{
		return true;
	}
	maze[x][y] = '.';
	return false;
}

//main function

int main()
{
	bool u;
	std::cout<<"Enter the coordinates according to the Cartesian Coordinate system \n"<<std::endl;
	
	do // Accepts x and y coordinates only if they are within the maze and if it does not belong to an obstacle.
	{
	std::cout << "Enter x and y coordinate for the Start" <<std::endl;
	std::cin>> c >>d;

	std::cout << "Enter x and y coordinate for the Goal" <<std::endl;
	std::cin>> a >>b;

	} while((a > 5) || (b > 5) || (c > 5) || (d > 5) || (maze[b][a] == '#') || (maze[d][c] == '#')); 
	


	maze[b][a] = 'G'; // Sets the Goal coordinates in the maze
	maze[d][c] = 'S'; // Sets the Start coordinates in the maze

	std::cout<<"\n";
	std::cout << "Input matrix" << std::endl;
	PrintMaze(maze); // Prints the Maze with the Start and Goal coordinates

	std::cout << "\n" <<std::endl;
	u = FindPath(d,c);
	if (u == true)
	{
		std::cout <<"Success! Path found! \n";
		std::cout <<"\n";
	}
	else
		std::cout <<"Path not found! \n";
		std::cout <<"\n";
 
 
	maze[d][c] = 'S';
	std::cout<<"Goal Path \n"<<std::endl;
	PrintMaze(maze); // Prints the Maze with the path from Start to the Goal coordinates.
	std::cout << "\n";
	return 0;
}

 
 
 
 
 
 
 


