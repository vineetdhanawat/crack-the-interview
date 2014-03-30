/*
	How can we sum the digits of a given number in single statement?
*/

# include<stdio.h>
void main()
{
	int num=123456;
	int sum=0;
	for(;num>0;sum+=num%10,num/=10); // This is the "single line".
	printf("\nsum = [%d]\n", sum);
}