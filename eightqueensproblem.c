/*
	What is the 8 queens problem?
	Write a C program to solve it.
*/

#include <stdio.h>
int matrix[8] = {-1};
void calculate(int);
int check(int);
void print();

void main()
{
	int i=0;
	//print();
	calculate(i);
	print();
}

void calculate(int i)
{
	for(matrix[i]=0;matrix[i]<8;matrix[i]++)
	{
		if(check(i))
		{
			if(i == 7)
			print();
			calculate(i+1);
		}
	}
}

int check(int i)
{
int j;
	for(j=0;j<i;j++)
	{
		if(!(matrix[i]!=matrix[j] && abs(matrix[i]-matrix[j])!=i-j))
		return 0;
	}
	return 1;
}

void print()
{
	int x;
	printf("\n\n");
	for(x=0;x<8;x++)
	{
		printf("%d %d \n",x,matrix[x]);
	}
}