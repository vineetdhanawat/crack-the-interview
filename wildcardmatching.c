/*
	Write a C program which does wildcard pattern matching algorithm.
*/

#include <stdio.h>
#include <stdbool.h>

bool wildcard(char *, char *);

void main()
{
	char string[] = "hello world";
	char pattern[] = "*ello*";
	printf("%s", wildcard(string, pattern) ? "true" : "false");
	//printf("%B",true);
}

bool wildcard(char *string, char *pattern)
{
	//printf("wildcard test");
	if(*pattern == '\0' && *string == '\0')
		return true;
	
	if(*pattern == '*' && *(pattern+1) != '\0' && *string == '\0')
		return false;
		
	if(*pattern == *string || *pattern == '?')
		return wildcard(string+1,pattern+1);
		
	if(*pattern == '*')
		return(wildcard(string,pattern+1) || wildcard(string+1,pattern));
		
	return false;
}