/*
	Write a C program to remove all duplicates from the sorted input array.
*/


#include<stdio.h>
void removeDuplicate(int[], int);
void printNoDuplicate(int[], int);

void main()
{
	int array[] ={1,2,3,4,4,5,6,6,6,6,7,8,9,10};
	removeDuplicate(array,12);
	printf("\n");
	printNoDuplicate(array,12);
}

void removeDuplicate(int array[], int n)
{
	int newarray[100];
	int i,j=0;
	int newsize;
	for(i=0;i<n;i++)
	{
		if(array[i] != newarray[j-1])
		{
			newarray[j]=array[i];
			j++;
		}
	}
	newsize = j;
	for(i=0;i<newsize;i++)
		printf("%d ",newarray[i]);
}

void printNoDuplicate(int array[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(array[i] != array[i+1])
		printf("%d ",array[i]);
	}
}