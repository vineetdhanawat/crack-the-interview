/*
	Write a C program to sort integers.
	Insertion sort Method
*/

#include<stdio.h>

void main()
{
	int array[] = {2,3,5,0,4,1,9,4};
	int length = sizeof(array) / sizeof(array[0]);
	int i,j,k,temp=0;

	for(i=1;i<length;i++)
	{

		if(array[i]<array[i-1])
		{
			j=i;
			temp = array[i];
			while(temp<array[j-1] && j>=1)
			{
				array[j] = array[j-1];
				j--;
			}
			array[j] = temp;
		}
	}
	for(k=0;k<length;k++)
	{
		printf("%d ",array[k]);
	}
	printf("\n");
}