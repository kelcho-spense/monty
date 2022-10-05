#include "monty.h"
/**
 * main - entry point to program
 * @argc: argument count
 * @argv: argument vector
 * Return: always success
 */
stack_t *head = NULL;
int main(int argc, char **argv)
{
	if (argc != 2)
		err(1);
	open_file(argv[1]);
	free_nodes();
	return (0);
}
