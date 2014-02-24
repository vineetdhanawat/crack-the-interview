/*
	How do you sort a linked list? 
	Write a C program to sort a linked list.
	Mergesort Method
*/

#include<stdio.h>
#include <stdlib.h>
struct node
{
    int number;
    struct node *next;

};

// Functions
struct node *addnode(int number,struct node *next);
struct node *mergesort(struct node *head);
struct node *merge(struct node *one,struct node *two);

int main(void)
{
    struct node *head;
    struct node *current;
    struct node *next;
    int test[]={8,3,1,4,2,5,7,0,11,14,6};
    int n=sizeof(test)/sizeof(test[0]);
    int i;
    head=NULL;
    for (i=0;i<n;i++)
         head=addnode(test[i],head);
    i=0;
    head=mergesort(head);
    printf("before----after sort \n");
    for (current=head;current!=NULL;current=current->next)
        printf("%4d\t%4d\n",test[i++],current->number);

    /* free list */
    for (current=head;current!=NULL;current=current->next)
        next=current->next;free(current);
	return 0;
}

struct node *addnode(int number,struct node* next)
{
    struct node *tnode;
    tnode=(struct node*)malloc(sizeof(*tnode));
    if(tnode!=NULL)
    {
        tnode->number=number;
        tnode->next=next;
    }
    return tnode;
}

struct node *mergesort(struct node *head)
{
    struct node *head_one;
    struct node *head_two;
    if((head==NULL) ||(head->next==NULL))
        return head;
    head_one=head;
    head_two=head->next;
    while( (head_two!=NULL) &&(head_two->next!=NULL))
    {
        head=head->next;
        head_two=head_two->next->next;
    }
    head_two=head->next;
    head->next=NULL;
	// can be written in two different calls
    return merge(mergesort(head_one),mergesort(head_two));
}

struct node *merge(struct node*head_one,struct node*head_two)
{
    struct node *head_three;
    if(head_one==NULL)
         return head_two;
    if(head_two==NULL)
         return head_one;
    if(head_one->number<head_two->number)
    {
        head_three=head_one;
        head_three->next=merge(head_one->next,head_two);
    }
    else
    {
        head_three=head_two;
        head_three->next=merge(head_one,head_two->next);
    }
    return head_three;
}
