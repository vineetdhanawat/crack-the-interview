/*
	How do you reverse a singly linked list?
	How do you reverse a doubly linked list?
	Write a C program to do the same.
	Recursive Method
*/

#include <stdio.h>

// Variables
typedef struct node
{
	int value;
	struct node *next;
}mynode;

// Globals.
mynode *head, *tail, *temp;

// Functions
void add(int value);
mynode* reverse_recurse(mynode *root);
void print_list();

// The main() function
int main()
{
	head=(mynode *)0;
	// Construct the linked list.
	add(1);
	add(2);
	add(3);
	//Print it
	print_list();
	// Reverse it.
	if(head != (mynode *)0)
	{
		temp = reverse_recurse(head);
		temp->next = (mynode *)0;
	}
	//Print it again
	print_list();
	return(0);
}

// Reverse the linked list recursively
//
// This function uses the power of the stack to make this
// *magical* assignment
//
// node->next->next=node;
//
// :)
mynode* reverse_recurse(mynode *root)
{
	if(root->next!=(mynode *)0)
	{
		reverse_recurse(root->next);
		root->next->next=root;
		return(root);
	}
	else
	{
		head=root;
	}
}

// Function to add new nodes to the linked list.
void add(int value)
{
	temp = (mynode *) malloc(sizeof(struct node));
	temp->next=(mynode *)0;
	temp->value=value;
	if(head==(mynode *)0)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		tail->next=temp;
		tail=temp;
	}
}

// Function to print the linked list.
void print_list()
{
	printf("\n\n");
	for(temp=head; temp!=(mynode *)0; temp=temp->next)
	{
		printf("[%d]->",(temp->value));
	}
	printf("[NULL]\n\n");
}