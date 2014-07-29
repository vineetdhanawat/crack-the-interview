/*
	Write a C program to solve Rat in a Maze problem.
	Backtracking Implementation
*/

#include <stdio.h>
#include <stdbool.h>
bool solveMaze(int[4][4], int [4][4],int,int);
#define N 4
void main()
{
	int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1},{0, 1, 0, 0},{1, 1, 1, 1}};
	int solution[4][4] = {{0}};
	int x=0,y=0;
	if(solveMaze(maze,solution,x,y))
		printMatrix(solution);
}

bool solveMaze(int maze[4][4], int solution[4][4], int x, int y)
{
	// Maze ends at [3][3] or [N-1][N-1]
	if(x==N-1 && y==N-1)
	{	
		solution[x][y]=1;
		return true;
	}
	if(maze[x][y] == 1)
	{
		solution[x][y]=1;
		if (solveMaze(maze,solution,x+1,y))
			return true;
		if (solveMaze(maze,solution,x,y+1))
			return true;
		solution[x][y]=0;
	}
	return false;
}

printMatrix(int solution[4][4])
{
	int i=0,j=0;
	for(i;i<N;i++)
	{
		for(j=0;j<N;j++)
		printf("%d ",solution[i][j]);
		printf("\n");
	}
}