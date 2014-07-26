/*
	Write a C program to implement stack using linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct mynode
{
	int value;
	struct mynode *next;
};
typedef struct mynode node;

node * getNode(int element)
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->value = element;
	temp->next = NULL;
	return temp;
}

void push(int element, node **top)
{
	if(*top==0)
	{
		node *temp;
		*top = (node*)malloc(sizeof(node));
		(*top)->value=element;
		(*top)->next=NULL;
		//*top=temp;
		printf("hello");
	}
	else
	{
		node *temp;
		temp = getNode(element);
		temp->next = *top;
		*top = temp;
	}
}

void pop(node **top)
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	printf("%d\n",(*top)->value);
	temp = *top;
	*top = (*top)-> next;
	free(temp);
}

void main()
{
	node *top;
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
			push(element,&top);
		}
		else
		{
			pop(&top);
		}

		printf("\n Continue? y | n:");
		scanf(" %c", &choice);
	}
	while(choice=='y' || choice=='Y');	
}