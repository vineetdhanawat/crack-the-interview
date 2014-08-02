/*
	Write a C program to generate random numbers.
*/

#include <stdio.h>
void main()
{
	srand(time(NULL));
	printf("%d \n",rand()%100);
}