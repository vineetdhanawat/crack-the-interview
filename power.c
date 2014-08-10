/*
	Write a C program to implement pow(x,n).
*/

#include <stdio.h>
int power(int, int);

void main()
{
	int x=5,y=2;
	printf("%d\n",power(x,y));
	printf("%d\n",poweropti(5,4));
}

int power(int x, int y)
{
	if(y!=1)
		return x*power(x,y-1);
	else
		return x;
}

int poweropti(int x, int n)
{
	if(n==0)
		return(1);
	else if(n%2==0)
		{
			return(power(x,n/2)*power(x,(n/2)));
		}
		else
		{
			return(x*power(x,n/2)*power(x,(n/2)));
		}
}