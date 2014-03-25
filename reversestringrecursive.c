/*
	Write a C program to reverse a string.
	Recursive Method
*/

#include <stdio.h>
#include <string.h>
static char str[]="STRING TO REVERSE";

int main(int argc, char *argv)
{
	printf("\nOriginal string : [%s]", str);
	// Call the recursion function
	reverse(0);
	printf("\nReversed string : [%s]", str);
	return(0);
}

int reverse(int pos)
{
	// Here I am calculating strlen(str) everytime.
	// This can be avoided by doing this computation
	// earlier and storing it somewhere for later use.
	if(pos<(strlen(str)/2))
	{
		char ch;
		// Swap str[pos] and str[strlen(str)-pos-1]
		ch = str[pos];
		str[pos]=str[strlen(str)-pos-1];
		str[strlen(str)-pos-1]=ch;
		// Now recurse!
		reverse(pos+1);
	}
}