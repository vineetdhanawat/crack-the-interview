/*
	How can we sum the digits of a given number?
*/

#include <stdio.h>
void calculateSum(int);

void main()
{
	int x=819;
	calculateSum(x);
}

void calculateSum(int x)
{
	int sum=0;
	while(x>0)
	{
		sum += x%10;
		x=x/10;
	}
	
	printf("%d",sum);
}