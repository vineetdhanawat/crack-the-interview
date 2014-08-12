/*
	Write a C program to find the min cost path from (0,0) to (R-1,C-1) in a matrix.
	Dynamic Programming
*/

#include <stdio.h>
#define R 3
#define C 3

int min(int i, int j, int k)
{
	return ((i<j)?i:j)<k?((i<j)?i:j):k;
}

int mincost(int cost[R][C])
{
	int mincost[R][C]={0};
	mincost[0][0]=cost[0][0];

	int i,j;
	for(i=1;i<R;i++)
		mincost[i][0] = mincost[i-1][0] + cost[i][0];
	for(j=1;j<R;j++)
		mincost[0][j] = mincost[0][j-1] + cost[0][j];

	for(i=1;i<R;i++)
	for(j=1;j<C;j++)
	{
		mincost[i][j] = min(mincost[i][j-1],mincost[i-1][j],mincost[i-1][j-1])+cost[i][j];
	}
	for(i=0;i<R;i++)
	for(j=0;j<C;j++)
		printf("%d ",mincost[i][j]);
	return mincost[R-1][C-1];
}

void main()
{
	int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
	printf("%d",mincost(cost));
}