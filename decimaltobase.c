/*
	Write a C progam to convert from decimal to any base (binary, hex, oct etc...).
*/

#include <stdio.h>
int main()
{
	decimal_to_anybase(10, 2);
	decimal_to_anybase(255, 16);
	//getch();
}

decimal_to_anybase(int n, int base)
{
	int i, m, digits[1000], flag;
	i=0;
	printf("\n\n[%d] converted to base [%d] : ", n, base);
	while(n)
	{
		m=n%base;
		digits[i]="0123456789abcdefghijklmnopqrstuvwxyz"[m];
		n=n/base;
		i++;
	}
	//Eliminate any leading zeroes
	for(i--;i>=0;i--)
	{
		if(!flag && digits[i]!='0')flag=1;
		if(flag)printf("%c",digits[i]);
	}
}