/*
	Write a C program to calculate median of two sorted arrays of same size
	Divide and Conquer Method
*/

#include <stdio.h>

int max(int x, int y)
{
    return x > y? x : y;
}
 
int min(int x, int y)
{
    return x > y? y : x;
}

int getMedian(int array[], int length)
{
	if(length%2 !=0)
		return array[(length-1)/2];
	else
		return (array[(length-2)/2] + array[(length-1)/2])/2;
}

int calculateMedian(int array1[],int array2[], int length)
{
	// border cases
    if (length == 1)
        return (array1[0] + array2[0])/2;
 
    if (length == 2)
        return (max(array1[0], array2[0]) + min(array1[1], array2[1])) / 2;

	int median1 = getMedian(array1,length);
	int median2 = getMedian(array2,length);
	if(median1 == median2)
		return median1;
	if(median1 > median2)
	{
		if (length%2 == 0)
            return calculateMedian(array1, array2+length/2 -1, length - length/2 + 1);
		else
			return calculateMedian(array1, array2+length/2, length- length/2);
	}
	else
	{
		if (length%2 == 0)
            return calculateMedian(array1+length/2 -1, array2, length - length/2 + 1);
		else
			return calculateMedian(array1+length/2, array2, length- length/2);
	}
}

void main()
{
	int array1[]={1,12,25,26,38};
	int array2[]={2,13,19,30,45};
	
	int length=sizeof(array1)/sizeof(int);
	
	printf("Median: %d",calculateMedian(array1,array2,length));
}