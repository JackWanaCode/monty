#include "monty.h"

/**
 * free_list - free double linked list
 * @stack: head of the double linked list
 * Return: 0 or 1
 */
global_var global_variable;
void free_list(stack_t *stack)
{
	stack_t *new = stack;

	if (stack == NULL)
		return;
	while (new)
	{
		stack = stack->next;
		free(new);
		new = stack;
	}
	stack = NULL;
}
