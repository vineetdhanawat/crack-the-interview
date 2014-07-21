/*
	Write a C program to sort integers.
	Radix sort Method
*/

#include <stdio.h>
int array[] = {0};
#define max 10
#define base 10
void radixSort(int array[])
{
	int i,largest=array[0];
	int temp[max];
	for(i=0;i<max;i++)
	{
		if(array[i]>largest)
		largest=array[i];
	}
	
	int arg=1;
	while(largest/arg > 0)
	{
		// number of bases
		int bucket[base]={0};
		for(i=0;i<max;i++)
			bucket[(array[i]/arg)%base]++;
		
		for(i=1;i<max;i++)
			bucket[i]+=bucket[i-1];

		for(i=0;i<max;i++)
			temp[--bucket[(array[i]/arg)%base]] = array[i];
			
		for(i=0;i<max;i++)
			array[i] = temp[i];
			
		arg *= 10;
	}
}
void main()
{
	int i;
	printf("Enter integers:\n");
	for(i=0;i<max;i++)
	scanf("%d",&array[i]);
	
	radixSort(array);
	
	for(i=0;i<max;i++)
	printf("%d ",array[i]);
}