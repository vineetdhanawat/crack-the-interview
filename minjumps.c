/*
	Write a C program to calculate minimum number of jumps to reach end.
	Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
	Output: 3 (1-> 3 -> 8 ->9)
*/

#include <stdio.h>
#include <limits.h>

int minJumps(int array[], int end)
{
	int jump[end];
	int i,j;
	jump[0]=0;
	for(i=1;i<=end;i++)
	{
		jump[i]=0;
		for(j=0;j<i;j++)
		{
			if((j+array[j])>=i)
			{
				jump[i] = jump[j]+1;
				//printf("%d ",jump[i]);
				break;
			}
		}
	}
	for(i=0;i<=end;i++)
		printf("%d ",jump[i]);
	return jump[end];
}

void main()
{
	int array[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(array)/sizeof(array[0]);
	printf("MinJumps: %d", minJumps(array, n-1));
}