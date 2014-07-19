/*
	Write a C program to sort integers.
	Bubble sort Method
*/

#include<stdio.h>
void bubbleSort(int[], int);
void swap(int[], int, int);

void main()
{
	int array[] = {2,3,5,8,1,0,9,4};
	int length = sizeof(array) / sizeof(array[0]);
	int k;

	bubbleSort(array,length);
	
	for(k=0;k<length;k++)
	{
		printf("%d ",array[k]);
	}
}

void bubbleSort(int array[], int length)
{
	int i,j;
	for(i=0;i<length-1;i++)
	{
		for(j=0;j<length-1;j++)
		{
			if(array[j] > array[j+1])
				swap(array,j,j+1);
		}
	}
}

void swap(int array[], int i, int j)
{
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}