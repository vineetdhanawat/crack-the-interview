/*
	Write your own atoi().
*/

#include<stdio.h>
#include<string.h>

void atoi(char digits[])
{
	int i,result=0;
	for(i=0;i<strlen(digits);i++)
	{
		result = result*10 + digits[i] - '0';
	}
	printf("%d",result);
}

void main()
{
	char digits[10];
	printf("Enter the string in digits:");
	scanf("%s", digits);
	atoi(digits);
}