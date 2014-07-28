/*
	Write a C program to print the nth Fibonacci number.
	F1=1, F2=1, F3=2, F4=3 etc
*/

#include <stdio.h>

int fibonacci(int);

void main()
{
	int x;
	printf("Enter the value of n:");
	scanf("%d",&x);
	printf("%d ",fibonacci(x));
}

int fibonacci(int x)
{
	if(x == 1 || x == 2)
		return 1;
	return (fibonacci(x-1)+fibonacci(x-2));
}