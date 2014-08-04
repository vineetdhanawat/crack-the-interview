/*
	Write a C program to check if array elements are consecutive.
	{83, 78, 80, 81, 79, 82} = true
*/

#include <stdio.h>
#include <stdlib.h>

checkConsecutive(int array[], int n)
{
	int i,min=array[0],max=array[0];
	//int visited[n];
	int *visited = (int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		if(array[i]<min)
		min = array[i];
		if(array[i]>max)
		max = array[i];
	}
	
	// number of elements check
	if(max-min+1==n)
	{
		// unique elements check
		for(i=0;i<n;i++)
		{
			if(visited[array[i]-min] == 0)
			{
				visited[array[i]-min] == 1;
			}
			else
				return 0;
		}
		
	}
	else
		return 0;
	return 1;
}

void main()
{
	int array[]={83, 78, 80, 81, 79, 82};
	int length = sizeof(array)/sizeof(array[0]);
	printf("%s",checkConsecutive(array,length)?"true":"false");
}
