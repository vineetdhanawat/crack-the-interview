/*
	Write a C program to sort integers.
	Radix sort Method
*/

#include <stdio.h>
#define base 10

void radixSort(int array[], int length)
{
	int bucket[base]={0};
	int temp[length];
	int i,largest=0;
	for(i=0;i<length;i++)
	{
		if(array[i]>largest)
		largest = array[i];
	}
	
	int arg=1;
	while(largest/arg>0)
	{
		// IMP: reset bucket everytime
		int bucket[base]={0};
		for(i=0;i<length;i++)
			bucket[(array[i]/arg)%base]++;

		for(i=1;i<base;i++)
			bucket[i] += bucket[i-1];
		
		for(i=length-1;i>=0;i--)
			temp[--bucket[(array[i]/arg)%base]] = array[i];
		
		for(i=0;i<length;i++)
			array[i] = temp[i];
		
		arg*=10;
	}
}

void main()
{
	int array[] = {535,44,423};
	int length = sizeof(array)/sizeof(array[0]);
	int k;
	
	radixSort(array,length);
	
	for(k=0;k<length;k++)
	{
		printf("%d ",array[k]);
	}
}