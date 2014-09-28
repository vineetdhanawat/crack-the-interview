/*
	Write a C program to implement binary search tree (BST) basic operations.
	Also construct full binary tree using preorder and postorder.
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

node* getNode(int value)
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->keyvalue = value;
	temp->left = 0;
	temp->right = 0;
	return temp;
}

void insert(node **tree, int value)
{
	node *temp;
	if(*tree == 0)
	{
		*tree = getNode(value);
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

node* constructTreeUtil(int pre[], int post[], int *preIndex, int l, int m, int size)
{
	node *root;
	if(l<=m && *preIndex<size)
	{
		root = getNode(pre[*preIndex]);
		++(*preIndex);
		
		if(l==m)
			return root;
		int i=l;
		for(i;i<=m;i++)
		{
			if(post[i] == pre[*preIndex])
				break;
		}
		if (i <= m)
		{
			root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
			root->right = constructTreeUtil(pre, post, preIndex, i+1, m, size);
		}
	}
	return root;
}

node* constructTree(int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size-1, size);
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
	
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
	int size = sizeof(pre)/sizeof(pre[0]);
	node *newroot = constructTree(pre, post, size);
	printf("INORDER\n");
	inorder(newroot);
}