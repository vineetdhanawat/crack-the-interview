/*
	Write a C program to check if a BST is valid or not.
*/

#include <stdio.h>
#include <stdlib.h>

struct mynode
{
	int value;
	struct mynode *left;
	struct mynode *right;
};
typedef struct mynode node;

node* getNode(int value)
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int checkBST(node *root, int min, int max)
{
	if(root == 0)
		return 1;

	if(root->value > max || root->value < min)
		return 0;

	return (checkBST(root->left, min, root->value-1) && checkBST(root->right, root->value+1, max));
}

void main()
{
	node *root,*newroot;
	root = getNode(4);
	root->left = getNode(2);
	root->right = getNode(5);
	root->left->left = getNode(1);
	root->left->right = getNode(3);

	// global max and min int
	printf("%s",checkBST(root,-32767,32767)?"true":"false");
	
	newroot = getNode(3);
	newroot->left = getNode(2);
	newroot->right = getNode(5);
	newroot->left->left = getNode(1);
	newroot->left->right = getNode(4);

	// global max and min int
	printf("%s",checkBST(newroot,-32767,32767)?"true":"false");
}