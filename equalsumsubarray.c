/*
	How do you calculate the subarray whole sum is equal to input. Positive integers array.
	Linear Time Algorithm
*/

#include <stdio.h>

void calculateSum(int array[], int size, int sum)
{
	int i,j, tempSum=0,index=0;
	for(i=0;i<size;i++)
	{
		tempSum += array[i];
		if(tempSum == sum)
		{
			printf("Sum found:");
			for(j=index;j<=i;j++)
			{
				printf("%d ",array[j]);
			}
			break;
		}
		while(tempSum > sum)
		{
			tempSum -= array[index];
			index++;
		}
	}
}

void main()
{
	int array[]={10, 6, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(array)/sizeof(int);
	int sum=9;
	calculateSum(array, size, sum);
}