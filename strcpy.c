/*
	Implement the strcpy(str1, str2) function.
*/

#include <stdio.h>
char* my_strcpy(char dest[], const char source[]);

int main()
{
	char dest[10];
	int j;
	
	my_strcpy(dest,"AABBCC");
	
	while (dest[j] != '\0')
	{
		printf( "%d %c\n", j, dest[j] );
		j++;
	}
	return(0);
}

char* my_strcpy(char dest[], const char source[])
{
	int i = 0;
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}