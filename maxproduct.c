/*
	Write a C program to find value of Maximum Product Cutting.
	n=10; 3x3x4
*/

#include <stdio.h>

int maximum(int x, int y, int z)
{
	return (((x>y)?x:y)>z)?((x>y)?x:y):z;
}

int maxProduct(int n)
{
	int max[n],i,j;
	max[0]=1;
	max[1]=1;
	max[2]=1;
	max[3]=2;
	for(i=4;i<=n;i++)
	{
		max[i] = 0;
		for(j=1;j<=i/2;j++)
		{
			max[i] = maximum(max[i],j*(i-j),j*max[i-j]);
		}
	}
	return max[n];
	/*for(i=0;i<=n;i++)
	{
		printf("%d ",max[i]);
	}*/
}

void main()
{
	int n=11;
	printf("Maxproduct of %d is :%d",n, maxProduct(n));
	//maxProduct(n);
}