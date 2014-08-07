/*
	Write a C program to check for palindromes.
*/

#include <stdio.h>
#include <string.h>

int palindromeCheck(char []);
void main()
{
	char string1[] = "I am a good boy";
	char string2[] = "yoy";

	printf("%s\n",palindromeCheck(string1)?"true":"false");
	printf("%s\n",palindromeCheck(string2)?"true":"false");
}

int palindromeCheck(char string[])
{
	int len = strlen(string);
	char *start, *end;
	start = string;
	end = string+len-1;
	while(start<=end)
	{
		if(*start != *end)
		return 0;
		start++;end--;
	}
	return 1;
}