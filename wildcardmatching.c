/*
	Write a C program which does wildcard pattern matching algorithm.
*/

#include<stdio.h>
#define TRUE 1
#define FALSE 0
int wildcard(char *string, char *pattern);
int main()
{
	char *string = "hereheroherr";
	char *pattern = "*hero*";
	if(wildcard(string, pattern)==TRUE)
	{
		printf("\nMatch Found!\n");
	}
	else
	{
		printf("\nMatch not found!\n");
	}
	return(0);
}

int wildcard(char *string, char *pattern)
{
	while(*string)
	{
		switch(*pattern)
		{
			case '*': 	
			{			
				do {++pattern;} while(*pattern == '*');
				if(!*pattern) return(TRUE);
				while(*string)
				{
					if(wildcard(string++,pattern)==TRUE)
					return(TRUE);
				}
				return(FALSE);
			}
			default : if(*string!=*pattern) return(FALSE); break;
		}
		++pattern;
		++string;
	}
	while (*pattern == '*')
		++pattern;

	return !*pattern;
}