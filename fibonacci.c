/*
	Write a C program to print the nth Fibonacci number.
	F1=1, F2=1, F3=2, F4=3 etc
	Recursion and Dynamic Programming Method
*/

#include <stdio.h>

int fibonacciRecursion(int);
int fibonacciDynamic(int);

void main()
{
	int x;
	printf("Enter the value of n:");
	scanf("%d",&x);
	printf("%d\n",fibonacciRecursion(x));
	printf("%d\n",fibonacciDynamic(x));
}

int fibonacciRecursion(int x)
{
	if(x == 1 || x == 2)
		return 1;
	return (fibonacciRecursion(x-1)+fibonacciRecursion(x-2));
}

int fibonacciDynamic(int x)
{
	int array[x],i;
	array[0]=array[1]=array[2]=1;
	for(i=3;i<=x;i++)
	{
		array[i]=array[i-1]+array[i-2];
	}
	return array[--i];
}