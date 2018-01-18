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

/* prepend node to linked list */
void sll_prepend(sll_node** head, int data);

/* insert node to linked list */
void sll_insert(sll_node** prev_node, int new_data);

/* append a node to the end of a list */
void sll_append(sll_node** head, int new_data);

/* delete a node with the given data */
void sll_delete_key(sll_node** head, int key);


/*--------------------------------------
Stack using singly linked list
--------------------------------------*/

/* stack node */
typedef struct stack_node
{
	int data;
	stack_node* prev;

} stack_node;

/* print all node data in a stack */
void stack_print(stack_node* n);

void push(stack_node** head, int data);

void pop(stack_node** head);

int top(stack_node** head);

bool is_empty(stack_node** head);





/*--------------------------------------
Main
--------------------------------------*/

int main()
{
	stack_node* stack = NULL;

	printf("%d\n", is_empty(&stack));

	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	pop(&stack);
	push(&stack, 6);

	if (!is_empty(&stack))
	{
		printf("%d\n", top(&stack));
	}

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


/* prepend a node to the top of a list */
void sll_prepend(sll_node** head, int data)
{
	sll_node* new_node;

	new_node = (sll_node*)malloc(sizeof(sll_node));

	new_node->data = data;

	new_node->next = (*head);

	*head = new_node;

}


/* insert a node after a given node */
void sll_insert(sll_node** prev_node, int new_data)
{
	sll_node* new_node;

	new_node = (sll_node*)malloc(sizeof(sll_node));

	if (*prev_node)
	{
		new_node->data = new_data;
		new_node->next = (*prev_node)->next;
		(*prev_node)->next = new_node;
	}
	else
	{
		(*prev_node) = new_node;
		(*prev_node)->data = new_data;
		(*prev_node)->next = NULL;
	}
	
}


/* append a node to the end of a list */
void sll_append(sll_node** head, int new_data)
{
	sll_node* new_node;
	sll_node* prev_node;

	new_node = (sll_node*)malloc(sizeof(sll_node));

	if (*head)
	{
		new_node->data = new_data;
		new_node->next = NULL;

		prev_node = *head;

		while (prev_node->next)
		{
			prev_node = prev_node->next;
		}

		prev_node->next = new_node;
	}
	else
	{
		(*head) = new_node;
		(*head)->data = new_data;
		(*head)->next = NULL;
	}

}


/* delete a node with the given data */
void sll_delete_key(sll_node** head, int key)
{
	if (*head)
	{
		sll_node* prev_node;
		sll_node* crnt_node;

		prev_node = NULL;
		crnt_node = (*head);

		while (crnt_node && crnt_node->data != key)
		{
			prev_node = crnt_node;
			crnt_node = crnt_node->next;
		}

		if (crnt_node && prev_node)
		{
			prev_node->next = crnt_node->next;
			free(crnt_node);
		}
		else if (crnt_node)
		{
			(*head) = crnt_node->next;
			free(crnt_node);
		}
	}

}



/*--------------------------------------
Stack using singly linked list
--------------------------------------*/

/* print all node data in a stack */
void stack_print(stack_node* n)
{
	while (n != NULL)
	{
		printf("%d\n", n->data);
		n = n->prev;
	}
}

void push(stack_node** head, int data)
{
	stack_node* new_node;

	new_node = (stack_node*)malloc(sizeof(stack_node));

	new_node->data = data;

	new_node->prev = (*head);

	*head = new_node;

}

void pop(stack_node** head)
{
	if (*head)
	{
		stack_node* temp;
		temp = *head;

		(*head) = (*head)->prev;
		free(temp);
	}
}

int top(stack_node** head)
{
	if (*head)
	{
		return (*head)->data;
	}
	else
	{
		return NULL;
	}
}

bool is_empty(stack_node** head)
{
	if (*head)
	{
		return false;
	}
	else
	{
		return true;
	}
}