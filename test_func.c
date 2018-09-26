#include "monty.h"

/**
 * main - test functions
 *
 * Return: 0 or 1
 */
unsigned line_number;
void push_n(stack_t **stack, const int num)
{
	stack_t *new;

	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "L%i : malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->next = (*stack);
	new->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new;
	(*stack) = new;
}

void pall(stack_t *stack)
{
	stack_t *curr = stack;

	if (stack == NULL)
		return;
	while (curr != NULL)
	{
		printf("%i\n", stack->n);
		curr = curr->next;
	}
}
