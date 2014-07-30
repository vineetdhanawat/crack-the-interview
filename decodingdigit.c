/*
	Write a C program to count possible decodings of a given digit sequence.
	Input: digits[] = "1234"
	Output: 3
	The possible decodings are "ABCD", "LCD", "AWD"
*/

#include <stdio.h>

int countDecoding(int digits[], int position)
{
	if(position == 1 || position == 0)
		return 1;
	if(digits[position-1] <=6 && digits[position-2] <= 2)
		return countDecoding(digits,position-1) + countDecoding(digits,position-2);
	else
		return countDecoding(digits,position-1);
}

void main()
{
	int digits[] = {1,2,3,4};
	int digitlength = sizeof(digits)/sizeof(digits[0]);
	printf("%d",countDecoding(digits,digitlength));
}