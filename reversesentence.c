/*
	Write a C program to reverse the words in a sentence in place.
*/

#include <stdio.h>
void rev(char *l, char *r);

int main(int argc, char *argv[])
{
	char buf[] = "the world will go on forever";
	char *end, *x, *y;
	
	// Reverse the whole sentence first..
	for(end=buf; *end; end++);
	rev(buf,end-1);
	
	// Now swap each word within sentence...
	x = buf-1;
	y = buf;
	while(x++ < end)
	{
		if(*x == '\0' || *x == ' ')
		{
			rev(y,x-1);
			y = x+1;
		}
	}
	// Now print the final string....
	printf("%s\n",buf);
	return(0);
}

// Function to reverse a string in place...
void rev(char *l,char *r)
{
	char t;
	while(l<r)
	{
		t = *l;
		*l++ = *r;
		*r-- = t;
	}
}