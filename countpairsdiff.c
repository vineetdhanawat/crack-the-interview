/*
	Count all distinct pairs with difference equal to k
*/

#include <stdio.h>
#define diff 4

void print(int array[], int length)
{
	int k;
	for(k=0;k<length;k++)
	{
		printf("%d ",array[k]);
	}
	printf("\n");
}

void merge(int array[], int i, int m, int j)
{
	int temp[1000];
	int counter=0;
	int low = i, mid = m, high = j, k,l;
	while(i<=mid && (m+1)<=high)
	{
		if(array[i] < array[m+1])
		{
			temp[counter] = array[i];
			i++;
		}
		else
		{
			temp[counter] = array[m+1];
			m++;
		}
		counter++;
	}
	while(i<=mid)
	{
		temp[counter] = array[i];
		i++;counter++;
	}
	while((m+1)<=high)
	{
		temp[counter] = array[m+1];
		m++;counter++;
	}
	
	
	for(k=high;k>=low;k--)
	{
		array[k] = temp[counter-1];
		counter--;
	}
}

void mergeSort(int array[], int i, int j)
{
	if(i<j)
	{
		int mid = (i+j)/2;
		mergeSort(array,i,mid);
		mergeSort(array,mid+1,j);
		merge(array,i,mid,j);
	}
}

void main()
{
	int array[]={8, 12, 16,17,3,21,4, 0, 20};
	int length = sizeof(array)/sizeof(array[0]);
	mergeSort(array,0,length-1);
	
	int i=0,j=1,count;
	while(i<=(length-1) && j<=(length-1))
	{
		if(array[j]-array[i] == diff && i != j)
		{
			count++;
			i++;
		}
		else
			if(array[j]-array[i] > diff)
				i++;
			else
				j++;
	}
	printf("pairs: %d", count);
}
