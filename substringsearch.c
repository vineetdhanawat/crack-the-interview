/*
	Write C code to implement the strstr() (search for a substring) function.
	Bruteforce Method
*/

#include<stdio.h>
#include <string.h>
void BruteForce(char *x /* pattern */,
int m /* length of the pattern */,
char *y /* actual string being searched */,
int n /* length of this string */)
{
	int i, j;
	printf("\nstring : [%s]"
	"\nlength : [%d]"
	"\npattern : [%s]"
	"\nlength : [%d]\n\n", y,n,x,m);
	/* Searching */
	for (j = 0; j <= (n - m); ++j)
	{
		for (i = 0; i < m && x[i] == y[i + j]; ++i);
		if (i >= m)
		{
			printf("\nMatch found at\n\n->[%d]\n->[%s]\n",j,y+j);
		}
	}
}

int main()
{
	char *string = "hereroheroero";
	char *pattern = "hero";
	BruteForce(pattern,strlen(pattern),string,strlen(string));
	printf("\n\n");
	return(0);
}