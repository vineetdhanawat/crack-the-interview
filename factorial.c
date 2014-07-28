/*
	Write a C program to calculate x! factorial.
*/

#include <stdio.h>
int factorial(int);

void main()
{
	int x;
	printf("Enter the number:");
	scanf("%d",&x);
	printf("%d ",factorial(x));
}

int factorial(int x)
{
	if(x!=1 && x!=0)
		return x*factorial(x-1);
	else
		return 1;
}