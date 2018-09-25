#include "monty.h"

/**
 * main - test functions
 *
 * Return: 0 or 1
 */
stack_t *push(stack_t **stack, const int num)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = num;
	new->next = (*stack);
	new->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new;
	(*stack) = new;
	return (*stack);
}

int pall(const stack_t *stack)
{
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		printf("%i\n", stack->n);
		stack = stack->next;
	}
	return (0);
}
