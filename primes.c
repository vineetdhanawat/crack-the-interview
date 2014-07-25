/*
	Write a C program to generate first 100 primes.
*/

#include <stdio.h>
#include <stdbool.h>

bool primeTest(int [], int);
#define COUNT 100

void main()
{
	int i=2;
	int foundPrime[100] = {0};
	int primeCount=0;

	while(primeCount<100)
	{
		foundPrime[0] = 2;
		if(primeTest(foundPrime, i))
		{
			printf("%d ",i);
			foundPrime[primeCount]=i;
			primeCount++;
		}
		i++;
	}
}

bool primeTest(int foundPrime[], int number)
{
	int i;
	for(i=0;i<COUNT;i++)
	{
		if(foundPrime[i]!= 0)
		{
			if(number % foundPrime[i] == 0)
				return false;
		}
		else
			return true;
	}
	return true;
}