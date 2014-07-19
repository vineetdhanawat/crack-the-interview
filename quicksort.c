/*
	Write a C program to sort integers.
	Quick sort Method
*/

#include<stdio.h>
void quickSort(int[], int, int);
void swap(int[], int, int);
int partition(int[], int, int);

void main()
{
	int array[] = {2,3,5,8,1,0,9,4};
	int length = sizeof(array) / sizeof(array[0]);
	int i,j,k,temp=0;

	quickSort(array,i,length-1);
	
	for(k=0;k<length;k++)
	{
		printf("%d ",array[k]);
	}
}

void quickSort(int array[], int i, int j)
{
	int pivot;
	if(i<j)
	{
		pivot = partition(array,i,j);
		quickSort(array,i,pivot-1);
		quickSort(array,pivot+1,j);
	}
}

int partition(int array[], int i, int j)
{
	int k;
	int pivot= (i+j)/2;
	int low=i,high=j;
	int counter=low;
	int pivotValue = array[pivot];

	swap(array,pivot,j);
	
	for(low;low<=high;low++)
	{
		if(array[low]<pivotValue)
		{
			swap(array,low,counter);
			counter++;
		}
	}
	swap(array,counter,j);
	return counter;
}

void swap(int array[], int i, int j)
{
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}