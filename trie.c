/*
	Trie Implementation for Insert and Search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mynode
{
	int value;
	struct mynode *next[26];
};
typedef struct mynode node;

struct trie
{
	node *root;
	int count;
};
typedef struct trie trietree;

int charIndex(char c)
{
	return (int) c - (int) 'a';
}

node* getNode(int value)
{
	int i;
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->value = value;
	for(i=0;i<26;i++)
	{
		temp->next[i] = NULL;
	}
	return temp;
}

void initialize(trietree *basetrie)
{
	basetrie->root = getNode(0);
	basetrie->count = 0;
}

void insert(trietree *basetrie, char string[])
{
	node *traverse;
	int length = strlen(string);
	int i,index;
	
	traverse = basetrie->root;
	basetrie->count++;
	// level of tree
	for(i=0;i<length;i++)
	{
		// i corresponds to level at which that char will be stored
		// index is corresponding 0-25 index of that char
		index = charIndex(string[i]);
		if(traverse->next[index] == 0)
		{
			traverse->next[index] = getNode(0);
		}
		traverse = traverse->next[index];
	}
	
	// magic: leaf node logic
	traverse->value=basetrie->count;
}

int search(trietree *basetrie, char string[])
{
	node *traverse;
	int length = strlen(string);
	int i,index;
	
	traverse = basetrie->root;
	// level of tree
	for(i=0;i<length;i++)
	{
		// i corresponds to level at which that char will be stored
		// index is corresponding 0-25 index of that char
		index = charIndex(string[i]);
		if(traverse->next[index] == 0)
		{
			return 0;
		}
		traverse = traverse->next[index];
	}
	
	// magic: leaf node logic
	return(traverse!=0 && traverse->value!=0);
}

int main()
{
	trietree basetrie;
	initialize(&basetrie);
	insert(&basetrie,"the");
	insert(&basetrie,"they");
	insert(&basetrie,"these");
	printf("%s \n",search(&basetrie,"the")?"true":"false");
	printf("%s \n",search(&basetrie,"thes")?"true":"false");
	printf("%s \n",search(&basetrie,"they")?"true":"false");
}
