/*
	How do you calculate the maximum subarray of a list of numbers?
	Kadane Algorithm
*/

#include <stdio.h>

void main()
{
	int array[]={11, -12, 15, -3, 8, -9, 1, 8, 10, -2};
	int size = sizeof(array)/sizeof(int);
	int i=0,j=0,k=0;
	int sum=0, maxsum=0;
	for(i;i<size;i++)
	{
		sum+= array[i];
		if(sum>0)
		{
			if(sum>maxsum)
				maxsum=sum;
		}
		else
		sum=0;
	}	
	printf("sum: %d",maxsum);
}