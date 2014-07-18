/*
	Write a C program to sort integers.
	Merge sort Method
*/

#include<stdio.h>
void mergeSort(int[], int, int);
void merge(int[], int, int, int);

void main()
{
	int array[] = {2,3,5,8,1,0,9,4};
	int length = sizeof(array) / sizeof(array[0]);
	int i,j,k,temp=0;

	mergeSort(array,0,length-1);
	for(k=0;k<length;k++)
	{
		printf("%d ",array[k]);
	}
}

void mergeSort(int array[], int i, int j)
{
	int m;
	if(i<j)
	{
		m = (i+j)/2;
		mergeSort(array,i,m);
		mergeSort(array,m+1,j);
		merge(array,i,m,j);
	}
}

void merge(int array[], int i, int m, int j)
{
	int tempArray[100];
	int low=i,mid=m,high=j,k,l;
	int counter=0;
	while(i<=mid && (m+1)<=high)
	{
		if(array[i]<=array[m+1])
		{
			tempArray[counter] = array[i];
			i++;
		}
		else
		{
			tempArray[counter] = array[m+1];
			m++;
		}
		counter++;
	}

	while(i<=mid)
	{
		tempArray[counter] = array[i];
		i++;counter++;
	}

	while((m+1)<=high)
	{
		tempArray[counter] = array[m+1];
		m++;counter++;
	}
	
	for(k=low,l=0;k<=high;k++,l++)
	{
         array[k]=tempArray[l];
    }
}
  