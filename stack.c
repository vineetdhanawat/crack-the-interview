/*
	Write a C program to implement stack using array.
*/

#include<stdio.h>

int frontPosition=0;
int rearPosition=0;
#define max 10
int array[max]={0};

void push(int element)
{
	int i;
	if(frontPosition<max)
	{
		array[frontPosition++] = element;
		printf("Pushed\n");
	}
	
	for(i=0;i<max;i++)
		printf("%d ",array[i]);
	printf("\n");
}
void pop()
{
	int i;
	if(frontPosition>rearPosition)
	{
		--frontPosition;
		printf("%d\n",array[frontPosition]);
	}
	for(i=0;i<max;i++)
	printf("%d ",array[i]);
	printf("\n");
}

void main()
{
	int option,element;
	char choice;
	do
	{
		printf("Push or Pop | 1 or 2:");
		scanf("%d",&option);
		if(option==1)
		{	
			printf("\n Enter element:");
			scanf("%d",&element);
			push(element);
		}
		else
		{
			pop();
		}

		printf("\n Continue? y | n:");
		scanf(" %c", &choice);
	}
	while(choice=='y' || choice=='Y');	
}