#include "stdafx.h"
#include <stdlib.h>

/*--------------------------------------
Singly Linked List
--------------------------------------*/

/* Singly linked list node */
typedef struct sll_node
{
	int data;
	sll_node* next;

} sll_node;

/* print all node data in a singly linked list */
void sll_print(sll_node* head);




int main()
{
	sll_node* head = (sll_node*)malloc(sizeof(sll_node));
	sll_node* node2 = (sll_node*)malloc(sizeof(sll_node));
	sll_node* node3 = (sll_node*)malloc(sizeof(sll_node));

	head->data = 0;
	head->next = node2;

	node2->data = 1;
	node2->next = node3;

	node3->data = 2;
	node3->next = NULL;

	sll_print(head);

	getchar();

    return 0;
}


/*--------------------------------------
Singly Linked List
--------------------------------------*/

/* print all node data in a singly linked list */
void sll_print(sll_node* n)
{
	while (n != NULL)
	{
		printf("%d\n", n->data);
		n = n->next;
	}
}