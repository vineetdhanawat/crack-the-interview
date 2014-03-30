/*
	Write a C program to check for palindromes.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void isPalindrome(char *string);
int main()
{
	isPalindrome("avon sees nova");
	isPalindrome("a");
	isPalindrome("avon sies nova");
	isPalindrome("aa");
	isPalindrome("abc");
	isPalindrome("aba");
	isPalindrome("3a2");
	exit(0);
}

void isPalindrome(char *string)
{
	char *start, *end;
	if(string)
	{
		start = string;
		end = string + strlen(string) - 1;
		while((*start == *end) && (start!=end))
		{
			if(start<end)start++;
			if(end>start)end--;
		}
		if(*start!=*end)
		{
			printf("\n[%s] - This is not a palidrome!\n", string);
		}
		else
		{
			printf("\n[%s] - This is a palidrome!\n", string);
		}
	}
	printf("\n\n");
}