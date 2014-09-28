/*
	Write a C program to sort integers.
	Heap sort Method
*/

#include <stdio.h>

void swap(int array[], int i, int j)
{
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void heapsort(int array[], int length)
{
	int i;
	int root,j;
	for(i=0;i<length;i++)
	{
		j=i;
		root=j;
		do
		{
			root /= 2;
			if(array[root] < array[j])
			{
				swap(array,root,j);
			}
			j = root;
		}
		while(root!=0);
	}
}

void main()
{
	int array[]={4,1,7,5,2,9,6};
	int length = sizeof(array)/sizeof(array[0]);

	int i,templength;
	templength = length;
	for(i=0;i<length;i++)
	{
		heapsort(array,templength);
		swap(array,0,--templength);
	}
	
	for(i=0;i<length;i++)
		printf("%d ",array[i]);
}  