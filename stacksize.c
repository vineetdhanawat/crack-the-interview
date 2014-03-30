/*
	Write a program to check if the stack grows up or down.
*/

#include <stdio.h>
#include <stdlib.h>
void stack(int *local1);
int main()
{
	int local1;
	stack(&local1);
	exit(0);
}
void stack(int *local1)
{
	int local2;
	printf("\nAddress of first local : [%u]", local1);
	printf("\nAddress of second local : [%u]", &local2);
	if(local1 < &local2)
	{
		printf("\nStack is growing downwards.\n");
	}
	else
	{
		printf("\nStack is growing upwards.\n");
	}
	printf("\n\n");
}