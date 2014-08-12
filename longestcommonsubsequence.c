/*
	Write a C program to find the length of longest subsequence present.
	LCS for input Sequences "ABCDGH" and "AEDFHR" is "ADH" of length 3.
	LCS for input Sequences "AGGTAB" and "GXTXAYB" is "GTAB" of length 4.
*/

#include <stdio.h>
#include <string.h>

int max(int x, int y)
{
	return (x>y)?x:y;
}

int lcsrecursion(char string1[], char string2[], int m, int n)
{
	if(m <0 || n < 0)
		return 0;
	else
	{
		if(string1[m]==string2[n])
			return 1+lcsrecursion(string1,string2,m-1,n-1);
		else
			return max(lcsrecursion(string1,string2,m-1,n),lcsrecursion(string1,string2,m,n-1));
	}
}

int lcsdynamic(char string1[], char string2[], int m, int n)
{
	int lcs[m][n],i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				lcs[i][j] = 0;
			else if (string1[i-1]==string2[j-1])
				lcs[i][j] = 1+ lcs[i-1][j-1];
			else
				lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
		}
	}
	return lcs[m][n];
}

void main()
{
	char string1[] = "AGGTAB";
	char string2[] = "GXTXAYB";

	int m = strlen(string1);
	int n = strlen(string2);
	printf("Length of LCS is %d\n", lcsrecursion(string1,string2,m-1,n-1));
	printf("Length of LCS is %d\n", lcsdynamic(string1,string2,m,n));
}