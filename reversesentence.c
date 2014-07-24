/*
	Write a C program to reverse the words in a sentence in place.
*/

#include <stdio.h>
#include <string.h>
void reversestring(char[], char *, char *);
void print(char[]);

void main()
{
	char *start, *end;
	char string[50] = "I am a good boy";
	start = string;
	end = strlen(string)+start-1;
	reversestring(string, start, end);
	char *newstart=start;
	for(start;start<end;start++)
	{
		if(*start == '\0' || *start == ' ')
		{
			reversestring(string, newstart, start-1);
			newstart = start+1;
		}
	}

	print(string);
}

void reversestring(char string[], char *start, char *end)
{
	char temp;
	while(start<end)
	{
		temp=*start;
		*start = *end;
		*end = temp;
		start++;end--;
	}
}

void print(char string[])
{
	int i=0;
	for(i;i<strlen(string);i++)
		printf("%c ",string[i]);
}