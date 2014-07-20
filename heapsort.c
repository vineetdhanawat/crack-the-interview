/*
	Write a C program to sort integers.
	Heap sort Method
*/

#include<stdio.h>
void heapSort(int[], int);
void swap(int[], int, int);

void main()
{
	int array[] = {2,3,5,8,1,0,9,4};
	int length = sizeof(array) / sizeof(array[0]);
	int i,j,k,temp=0;
	int tempLength;

	heapSort(array,length);

	tempLength=length;
	for(i=0;i<length;i++)
	{
		swap(array,length-1-i,0);
		heapSort(array,--tempLength);
	}
	for(k=0;k<length;k++)
	{
		printf("%d ",array[k]);
	}
}

void heapSort(int array[], int length)
{
	int i=0,j=0,k,root;
	for(i=0;i<length;i++)
	{
		root = i;
		j = i;
		do
		{
			root = (root-1)/2;
			if(array[root]<array[j])
			{
				swap(array,root,j);
			}
			j = root;
		}while(root!=0);
	}
}

void swap(int array[], int i, int j)
{
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
  