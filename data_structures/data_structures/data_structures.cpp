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
Binary Search Tree
--------------------------------------*/

typedef struct bst_node
{
	int data;
	bst_node* left;
	bst_node* right;

} bst_node;

void insert_leaf(bst_node** root, int new_data);

bst_node* search_tree(bst_node* root, int data);

void print_tree(bst_node* root);






/*--------------------------------------
Main
--------------------------------------*/

int main()
{
	bst_node* root = NULL;
	bst_node* result;

	insert_leaf(&root, 10);
	insert_leaf(&root, 8);
	insert_leaf(&root, 7);
	insert_leaf(&root, 9);
	insert_leaf(&root, 12);
	insert_leaf(&root, 11);
	insert_leaf(&root, 13);

	print_tree(root);

	result = search_tree(root, 7);

	if (result)
	{
		printf("Data %d found.\n", result->data);
	}
	else
	{
		printf("Data not found.");
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


/*--------------------------------------
Binary Search Tree
--------------------------------------*/

void insert_leaf(bst_node** root, int new_data)
{
	if (*root)
	{
		if (new_data < (*root)->data)
		{
			insert_leaf(&(*root)->left, new_data);
		}
		else
		{
			insert_leaf(&(*root)->right, new_data);
		}
	}
	else
	{
		bst_node* new_node = (bst_node*)malloc(sizeof(bst_node));

		new_node->data = new_data;
		new_node->left = NULL;
		new_node->right = NULL;

		(*root) = new_node;
	}
	return;
}

bst_node* search_tree(bst_node* root, int data)
{
	bst_node* tmp = root;

	if (root)
	{
		if (data < root->data)
		{
			tmp = search_tree(root->left, data);
		}
		else if (data > root->data)
		{
			tmp = search_tree(root->right, data);
		}
	}
	
	return tmp;
}

void print_tree(bst_node* root)
{
	if (root)
	{
		print_tree(root->left);
		printf("%d\n", root->data);
		print_tree(root->right);
	}

	return;
}