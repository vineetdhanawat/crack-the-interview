/*
	How do you reverse a singly linked list?
	How do you reverse a doubly linked list?
	Write a C program to do the same.
	Recursive Method, but without ANY global variables. Slightly messy!
*/

#include <stdio.h>

// Variables
typedef struct node
{
	int value;
	struct node *next;
}mynode;

// Functions
void add(mynode **head, mynode **tail, int value);
mynode* reverse_recurse(mynode *current, mynode *next);
void print_list(mynode *);

int main()
{
	mynode *head, *tail;
	head=(mynode *)0;
	// Construct the linked list.
	add(&head, &tail, 1);
	add(&head, &tail, 2);
	add(&head, &tail, 3);
	//Print it
	print_list(head);
	// Reverse it.
	head = reverse_recurse(head, (mynode *)0);
	//Print it again
	print_list(head);
	getch();
	return(0);
}

// Reverse the linked list recursively
mynode* reverse_recurse(mynode *current, mynode *next)
{
	mynode *ret;
	if(current==(mynode *)0)
	{
		return((mynode *)0);
	}
	ret = (mynode *)0;
	if (current->next != (mynode *)0)
	{
		ret = reverse_recurse(current->next, current);
	}
	else
	{
		ret = current;
	}
	current->next = next;
	return ret;
}

// Function to add new nodes to the linked list.
// Takes pointers to pointers to maintain the
// *actual* head and tail pointers (which are local to main()).
void add(mynode **head, mynode **tail, int value)
{
	mynode *temp1, *temp2;
	temp1 = (mynode *) malloc(sizeof(struct node));
	temp1->next=(mynode *)0;
	temp1->value=value;
	if(*head==(mynode *)0)
	{
		*head=temp1;
		*tail=temp1;
	}
	else
	{
		for(temp2 = *head; temp2->next!= (mynode *)0; temp2=temp2->next);
			temp2->next = temp1;

        *tail=temp1;

	}
}

// Function to print the linked list.
void print_list(mynode *head)
{
	mynode *temp;
	printf("\n\n");
	for(temp=head; temp!=(mynode *)0; temp=temp->next)
	{
		printf("[%d]->",(temp->value));
	}
	printf("[NULL]\n\n");
}
