/*
	Write a C program to implement binary search tree (BST) basic operations.
*/

#include <stdio.h>
#include <stdlib.h>

struct treenode
{
	int keyvalue;
	struct treenode *right;
	struct treenode *left;
} ;

typedef struct treenode node;

void insert(node **tree, int value)
{
	node *temp;
	if(*tree == 0)
	{
		temp = (node*)malloc(sizeof(node));
		temp->keyvalue = value;
		temp->left = 0;
		temp->right = 0;
		*tree = temp;
	}
	else if(value<(*tree)->keyvalue)
		insert(&((*tree)->left),value);
	else if(value>(*tree)->keyvalue)
		insert(&((*tree)->right),value);
}

void preorder(node *tree)
{
	if(tree)
	{
		printf("%d \n", tree->keyvalue);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(node *tree)
{
	if(tree)
	{
		inorder(tree->left);
		printf("%d \n", tree->keyvalue);
		inorder(tree->right);
	}
}

void postorder(node *tree)
{
	if(tree)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d \n", tree->keyvalue);
	}
}

void main()
{
	node *root;
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);
	printf("PREORDER\n");
	preorder(root);
	printf("INORDER\n");
	inorder(root);
	printf("POSTORDER\n");
	postorder(root);
}