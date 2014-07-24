/*
	Write a C program to check for palindromes.
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
		sum += array[i]
		if(sum > maxsum)
			maxsum = sum;
		else if(sum <0)
			sum = 0;
	}
	
	printf("sum: %d",maxsum);
}