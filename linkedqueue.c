/*
	Write a C program to implement queue using linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct mynode
{
	int value;
	struct mynode *next;
};
typedef struct mynode node;

node* getNode(int element)
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->value = element;
	temp->next = NULL;
	return temp;
}

void enqueue(int element, node **front, node **rear)
{
	if(*front==0 && *rear==0)
	{
		*front = (node*)malloc(sizeof(node));
		(*front)->value=element;
		(*front)->next=NULL;
		*rear = *front;
		printf("new enqueue\n");
	}
	else
	{
		node *temp;
		temp = getNode(element);
		temp->next=NULL;
		(*rear)->next = temp;
		*rear = temp;
		printf("enqueue\n");
	}
}

void dequeue(node **front, node **rear)
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	printf("%d\n",(*front)->value);
	temp = *front;
	*front = (*front)-> next;
	temp->next=NULL;
	free(temp);
	printf("dequeue\n");
}

void main()
{
	node *front,*rear;
	int option,element;
	char choice;
	do
	{
		printf("Enqueue or Dequeue | 1 or 2:");
		scanf("%d",&option);
		if(option==1)
		{	
			printf("\n Enter element:");
			scanf("%d",&element);
			enqueue(element,&front,&rear);
		}
		else
		{
			dequeue(&front,&rear);
		}

		printf("\n Continue? y | n:");
		scanf(" %c", &choice);
	}
	while(choice=='y' || choice=='Y');	
}