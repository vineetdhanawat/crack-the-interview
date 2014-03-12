/*
	Write C code to implement the strstr() (search for a substring) function.
	Knuth Morris Pratt Method
*/

#include<stdio.h>
#include<string.h>

void preComputeData(char *x, int m, int Next[])
{
	int i, j;
	i = 0;
	j = Next[0] = -1;
	while (i < m)
	{
		while (j > -1 && x[i] != x[j])
		j = Next[j];
		Next[++i] = ++j;
	}
}

void MorrisPrat(char *x, int m, char *y, int n)
{
	int i, j, Next[1000];
	/* Preprocessing */
	preComputeData(x, m, Next);
	/* Searching */
	i = j = 0;
	while (j < n)
	{
		while (i > -1 && x[i] != y[j])
			i = Next[i];
		i++;
		j++;
		if (i >= m)
		{
			printf("\nMatch found at : [%d]\n",j - i);
			i = Next[i];
		}
	}
}

int main()
{
	char *string="hereroheroero";
	char *pattern="hero";
	MorrisPrat(pattern,strlen(pattern),string,strlen(string));
	printf("\n\n");
	return(0);
}