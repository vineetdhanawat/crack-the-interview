/*
	Write a C program to implement Breadth first search (BFS) and Depth first search (DFS).
*/

#include <stdio.h>
void bfs(int);
void dfs(int);
void insert(int);
void addtostack(int);

int queue[5]={0};
int visited[5]={0};
int visited2[5]={0};
int graph[][5]={{0,0,0,1,1},{0,0,1,1,0},{0,1,0,0,1},{1,1,0,0,0},{1,0,1,0,0}};
int queueRearCounter=0;
int queueFrontCounter=0;
int stack[5]={0};
int stackRearCounter=0;
int stackFrontCounter=0;
#define count 5

void main()
{
	int startingNodeID=3;
	printf("BFS: ");
	bfs(startingNodeID);

	printf("\nDFS: ");
	dfs(startingNodeID);
}

void insert(int nodeID)
{
	queue[queueRearCounter]=nodeID;
	queueRearCounter++;
}

void addtostack(int nodeID)
{
	stack[stackFrontCounter]=nodeID;
	stackFrontCounter++;
}

void dfs(int nodeID)
{
	printf("%d ",nodeID);
	visited2[nodeID]=1;
	int i=0;
	for(i;i<count;i++)
	{
		if(graph[nodeID][i]==1 && visited2[i]==0)
		{
			visited2[i]=1;
			//printf("adding to stack %d \n",i);
			addtostack(i);
		}
	}
	while(stackFrontCounter>stackRearCounter)
	{
		//visited[queue[queueFrontCounter]]=1;
		//printf("bfs call %d \n",stack[stackFrontCounter]);
		dfs(stack[--stackFrontCounter]);
	}
}

void bfs(int nodeID)
{
	printf("%d ",nodeID);
	visited[nodeID]=1;
	int i=0;
	for(i;i<count;i++)
	{
		if(graph[nodeID][i]==1 && visited[i]==0)
		{
			visited[i]=1;
			insert(i);
			//printf("added %d \n",i);
		}
	}
	while(queueFrontCounter<queueRearCounter)
	{
		//visited[queue[queueFrontCounter]]=1;
		//printf("bfs call %d \n",queue[queueFrontCounter]);
		bfs(queue[queueFrontCounter++]);
	}	
}