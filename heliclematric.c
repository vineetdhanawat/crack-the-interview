/*
	Write a C program to print a square matrix helically.
*/

#include <stdio.h>
void print(int, int, int[5][4]);

void main()
{
	int matrix[5][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
	print(5,4,matrix);
}

void print(int row, int column, int matrix[5][4])
{
	int left=0,right=column-1,top=0,bottom=row-1;
	int i,j;
	while(1)
	{
		if(left > right || top > bottom)
			break;
		
		for(j=left;j<=right;j++)
			printf("%d ",matrix[top][j]);
		top++;

		for(i=top;i<=bottom;i++)
			printf("%d ",matrix[i][right]);
		right--;
		
		for(j=right;j>=left;j--)
			printf("%d ",matrix[bottom][j]);
		bottom--;
		
		for(i=bottom;i>=top;i--)
			printf("%d ",matrix[i][left]);
		left++;
	}
}