/*
	What is the 8 queens problem?
	Write a C program to solve it.
*/

#include<stdio.h>
#include<stdlib.h>

static int t[10]={-1};
void queens(int i);
int empty(int i);
void print_solution();

int main()
{
	queens(1);
	//print_solution();
	return(0);
}

void queens(int i)
{
	for(t[i]=1;t[i]<=8;t[i]++)
	{
		if(empty(i))
		{
			if(i==8)
			{
				
				print_solution();
				printf("\n");
				/* If this exit is commented, it will show ALL possible combinations */
				exit(0);
			}
			else
			{
				// Recurse!
				queens(i+1);
			}
		}// if
	}// for
}

int empty(int i)
{
	int j;
	j=1;
	while(t[i]!=t[j] && abs(t[i]-t[j])!=(i-j) &&j<8)
		j++;
	return((i==j)?1:0);
}

void print_solution()
{
	int i;
	for(i=1;i<=8;i++)
	printf("\nt[%d] = [%d]",i,t[i]);
}