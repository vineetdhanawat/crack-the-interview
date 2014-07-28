/*
	Write a C program to find the number of islands.
	Input matrix has land marked as 1 and water as 0.
	Diagonal land elements are not considered connected.
*/

#include <stdio.h>
#define ROW 5
#define COL 5

void dfs(int matrix[][COL], int visited[][COL], int i, int j)
{
	visited[i][j] = 1;

	if(matrix[i][j] == 1)
	{
		if(visited[i][j+1] == 0)
		 dfs(matrix,visited,i,j+1);
		if(visited[i+1][j] == 0)
		 dfs(matrix,visited,i+1,j);
		if(visited[i][j-1] == 0)
		 dfs(matrix,visited,i,j-1);
		if(visited[i-1][j] == 0)
		 dfs(matrix,visited,i-1,j);
	}
}

void countIslands(int matrix[ROW][COL])
{
	int visited[ROW][COL]={0};
	int counter=0,i,j;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(matrix[i][j] == 1 && visited[i][j] == 0)
			{
				dfs(matrix,visited,i,j);
				counter++;
			}
		}
	}
	printf("COUNTER: %d",counter);
}

void main()
{
	int matrix[ROW][COL]= {{1,1,0,0,0},{0,1,0,0,1},{1,0,0,1,1},{0,0,0,0,0},{1,0,1,0,1}};
	countIslands(matrix);
}