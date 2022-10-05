#include "monty.h"
stack_t *create_node(int n);
void free_nodes(void);
/**
 * create_node - function that creates a node
 * @n: integer value to be stored at node
 * Return: node
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
/**
 * free_nodes - function that frees node in stack
 * Return: nothing
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
