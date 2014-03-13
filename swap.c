/*
	Write a C program to swap two variables without using a temporary variable.
*/

#include <stdio.h>

int main()
{
	int a = 12, b = 6;
	int temp;
	
	// Method1 temp variable
	temp = a;
	a = b;
	b = temp;	
	printf("swap using temp a : %d\n",a);
	printf("swap using temp b : %d\n",b);
	
	// Method2 a+b
	a = a+b;
	b = a-b;
	a = a-b;
	printf("swap using a+b a : %d\n",a);
	printf("swap using a+b b : %d\n",b);
	
	// Method3 xor 	a ^= b ^= a ^= b;
	a = a^b;
	b = a^b;
	a = a^b;
	printf("swap using xor a : %d\n",a);
	printf("swap using xor b : %d\n",b);
}