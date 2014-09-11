#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
	int i=0;
	char temp;
	while(i<strlen(str)/2)
	{
		temp = str[i];
		str[i] = str[strlen(str)-1-i];
		str[strlen(str)-1-i] = temp;
		i++;
	}
}

void main()
{
	char string[]="lolakutty";
	int i=0;
	reverse(string);
	for(i;i<strlen(string);i++)
		printf("%c ",string[i]);
}