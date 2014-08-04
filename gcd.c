/*
	Write a C program to gcd of two numbers.
*/

#include<stdio.h>
void gcd(int, int);

void main()
{
	gcd(98,56);
}

void gcd(int x, int y)
{
	int temp;
	while(x>0)
	{
		temp = x;
		x = y%x;
		y = temp;
	}
	printf("%d",y);
}