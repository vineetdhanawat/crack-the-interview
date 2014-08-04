/*
	Write a C program to print next element of inorder traversal in a btree.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct treenode
{
	int keyvalue;
	struct treenode *right;
	struct treenode *left;
	struct treenode *parent;
} ;

typedef struct treenode node;

node* insert(node **tree, int value)
{
	node *temp;
	if(*tree == 0)
	{
		temp = (node*)malloc(sizeof(node));
		temp->keyvalue = value;
		temp->left = 0;
		temp->right = 0;
		temp->parent = 0;
		*tree = temp;
	}
	else if(value<(*tree)->keyvalue)
		{
			temp = insert(&((*tree)->left),value);
			temp->parent = *tree;
		}
		else if(value>(*tree)->keyvalue)
			{
				temp = insert(&((*tree)->right),value);
				temp->parent = *tree;
			}
	
	return *tree;
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

void nextinorder(node *tree, int value)
{
	if(tree)
	{
		if(tree->keyvalue == value)
		{
			if(tree->right)
				printf("NEXT:%d",tree->right->keyvalue);
			else
			{
				node *parent;
				parent = tree->parent;
				while(parent!=NULL && parent->right==tree)
				{
					tree=parent;
					parent=tree->parent;
				}
				printf("NEXT:%d",parent->keyvalue);
				exit(0);
			}
		}
		nextinorder(tree->left,value);
		//printf("%d \n", tree->keyvalue);
		nextinorder(tree->right,value);
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
	printf("NEXTINORDER\n");
	nextinorder(root,6);
}