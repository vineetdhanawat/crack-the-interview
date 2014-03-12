/*
	Write a C program to implement a Generic Linked List.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
	void *data;
	struct list *next;
} List;

struct check
{
	int i;
	char c;
	double d;
} chk[] = 	{
				{ 1, 'a', 1.1 },
				{ 2, 'b', 2.2 },
				{ 3, 'c', 3.3 }
			};

void insert(List **, void *, unsigned int);
void print(List *, void (*)(void *));
void printstr(void *);
void printint(void *);
void printchar(void *);
void printcomp(void *);

List *list1, *list2, *list3, *list4;

int main(void)
{
	char c[] = { 'a', 'b', 'c', 'd' };
	int i[] = { 1, 2, 3, 4 };
	char *str[] = { "hello1", "hello2", "hello3", "hello4" };
	list1 = list2 = list3 = list4 = NULL;
	insert(&list1, &c[0], sizeof(char));
	insert(&list1, &c[1], sizeof(char));
	insert(&list1, &c[2], sizeof(char));
	insert(&list1, &c[3], sizeof(char));
	insert(&list2, &i[0], sizeof(int));
	insert(&list2, &i[1], sizeof(int));
	insert(&list2, &i[2], sizeof(int));
	insert(&list2, &i[3], sizeof(int));
	insert(&list3, str[0], strlen(str[0])+1);
	insert(&list3, str[1], strlen(str[0])+1);
	insert(&list3, str[2], strlen(str[0])+1);
	insert(&list3, str[3], strlen(str[0])+1);
	insert(&list4, &chk[0], sizeof chk[0]);
	insert(&list4, &chk[1], sizeof chk[1]);
	insert(&list4, &chk[2], sizeof chk[2]);
	printf("Printing characters:");
	print(list1, printchar);
	printf(" : done\n\n");
	printf("Printing integers:");
	print(list2, printint);
	printf(" : done\n\n");
	printf("Printing strings:");
	print(list3, printstr);
	printf(" : done\n\n");
	printf("Printing composite:");
	print(list4, printcomp);
	printf(" : done\n");
	return 0;
}

void insert(List **p, void *data, unsigned int n)
{
	List *temp;
	int i;
	/* Error check is ignored */
	temp = malloc(sizeof(List));
	temp->data = malloc(n);
	for (i = 0; i < n; i++)
		*(char *)(temp->data + i) = *(char *)(data + i);
	temp->next = *p;
	*p = temp;
}

void print(List *p, void (*f)(void *))
{
	while (p)
	{
		(*f)(p->data);
		p = p->next;
	}
}

void printstr(void *str)
{
	printf(" \"%s\"", (char *)str);
}

void printint(void *n)
{
	printf(" %d", *(int *)n);
}

void printchar(void *c)
{
	printf(" %c", *(char *)c);
}

void printcomp(void *comp)
{
	struct check temp = *(struct check *)comp;
	printf(" '%d:%c:%f", temp.i, temp.c, temp.d);
}