/*
	Write a C progam to convert from decimal to any base (binary, hex, oct etc...).
*/

#include<stdio.h>
void decimaltobase(int,int);
void main()
{
	decimaltobase(5,2);
	decimaltobase(6,2);
	decimaltobase(7,2);
	decimaltobase(8,2);
	decimaltobase(9,2);
	decimaltobase(9,3);
	decimaltobase(1000,16);
}

void decimaltobase(int x, int y)
{
	int base[100];
	int i=0;
	int flag = 0;
	while(x>0)
	{
		//base[i] = x%y;
		base[i]="0123456789abcdefghijklmnopqrstuvwxyz"[x%y];
		x = x/y;
		//printf("%d : %d \n",i,base[i]);
		i++;
	}
	//printf("DONE \n");
	for(i;i>0;i--)
		if(!base[i-1] && !flag)
		{}
		else
		{	
			flag = 1;
			printf("%c ",base[i-1]);
		}
	printf("\n");	
}