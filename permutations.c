/*
	Write a C program generate permutations.
	Iterative and Recursive method
*/

#include <stdio.h>
#define SIZE 3
void permute(char list[],int k, int m);

int main(char *argv[],int argc)
{
	char list[3]={'a','b','c'};
	int i,j,k;
	
	// Iterative Permutation
	printf("Iterative Permutation \n");
	for(i=0;i<SIZE;i++)
	for(j=0;j<SIZE;j++)
	for(k=0;k<SIZE;k++)
	if(i!=j && j!=k && i!=k)
	printf("%c%c%c\n",list[i],list[j],list[k]);
	printf("\n\n");
	
	// Recursive Permutation
	printf("Recursive Permutation \n");
	permute(list,0,SIZE);
	return(0);
}

void permute(char list[],int k, int m)
{
	int i;
	char temp;
	if(k==m)
	{
		/* PRINT A FROM k to m! */
		for(i=0;i<SIZE;i++)
		{
			printf("%c",list[i]);
		}
		printf("\n");
	}
	else
	{
		for(i=k;i<m;i++)
		{
			/* swap(a[i],a[m-1]); */
			temp=list[i];
			list[i]=list[m-1];
			list[m-1]=temp;
			permute(list,k,m-1);
			/* swap(a[m-1],a[i]); */
			temp=list[m-1];
			list[m-1]=list[i];
			list[i]=temp;
		}
	}
}