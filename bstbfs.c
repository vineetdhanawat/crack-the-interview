/*
	Write a C program to implement binary search tree (BST) basic operations.
	Breadth First Search
*/

#include <stdio.h>
#include <stdlib.h>
#define QSIZE 500
struct treenode
{
	int keyvalue;
	struct treenode *right;
	struct treenode *left;
};
typedef struct treenode node;

void enqueue(node **queue, int *rear, node *element)
{
	queue[*rear]=element;
	(*rear)++;
}

node* dequeue(node **queue, int *front)
{
	(*front)++;
	return queue[*front - 1];
}

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

void bfs(node *tree)
{
	node **queue;
	int queueRearCounter=0;
	int queueFrontCounter=0;
	queue = (node**)malloc(sizeof(node*) * QSIZE);
	while(tree)
	{
		printf("%d ", tree->keyvalue);
		if(tree->left)
		enqueue(queue, &queueRearCounter, tree->left);

		if(tree->right)
		enqueue(queue, &queueRearCounter, tree->right);

		tree = dequeue(queue, &queueFrontCounter);
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

	printf("BFS\n");
	bfs(root);
}