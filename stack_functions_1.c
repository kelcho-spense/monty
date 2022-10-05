#include "monty.h"
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
void print_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
/**
 * add_to_stack - Adds a node to the stack LIFO.
 * (at the begining)
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * add_to_queue - Adds a node to the queue FIFO.
 * (at the end)
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of the opcode.
 * Return: nothing
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
/**
 * print_stack - prints nodes in the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * print_top - prints value at the top of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 * Return: nothing
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
/**
 * pop_top - removes the top element of the stack
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 * Return: nothing
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
