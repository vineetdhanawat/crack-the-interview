/*
	Write a C program to sort integers.
	Selection sort Method
*/

#include<stdio.h>
void swap(int[], int, int);

void main()
{
	int array[] = {2,3,5,0,6,1,9,4};
	int length = sizeof(array) / sizeof(array[0]);
	int i,j,k,temp=0;
	int min,minlocation;

	for(i=0;i<length;i++)
	{
		min = array[i];
		minlocation = i;
		for(j=i+1;j<length;j++)
		{
			if(array[j]<min)
			{
				min = array[j];
				minlocation = j;
			}
		}
		swap(array,i,minlocation);
		
		for(k=0;k<length;k++)
		{
			printf("%d ",array[k]);
		}
		printf("\n");
	}
}

void swap(int array[], int i, int minlocation)
{
	int temp;
	temp = array[i];
	array[i] = array[minlocation];
	array[minlocation] = temp;
}