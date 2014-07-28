/*
	Write a C program to find max of three numbers.
*/

#include<stdio.h>
void printmax(int, int, int);
void main()
{
	int x,y,z;
	printf("Enter the three numbers:");
	scanf("%d %d %d",&x,&y,&x);
	printmax(x,y,z);
}

void printmax(int x, int y, int z)
{
	printf("Largest no: %d",(((x>y)?x:y)>z)?((x>y)?x:y):z);
}