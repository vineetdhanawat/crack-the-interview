/*
	Implement the substr(str1, str2) function.
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "India";
	char str2[25];
	mysubstr(str2, str1, 1, 3);
	printf("\nstr2 : [%s]", str2);
	return(0);
}

mysubstr(char *dest, char *src, int position, int length)
{
	dest[0]='\0';
	strncat(dest, (src + position), length);
}