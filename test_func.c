#include "monty.h"

/**
 * main - test functions
 *
 * Return: 0 or 1
 */
int global_variable;
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;
	if (stack == NULL)
		printf("ERROR");
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		printf("ERROR");
	new->n = global_variable;
	new->next = (*stack);
	new->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new;
	(*stack) = new;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = (*stack);

	(void) line_number;
	if (stack == NULL)
		printf("ERROR");
	while (copy != NULL)
	{
		printf("%i\n", copy->n);
		copy = copy->next;
	}
}
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = (*stack);

	(void) line_number;
	if (stack == NULL)
		printf("ERROR");
	while (runner->next != NULL)
	{
		runner = runner->next;
	}
	while (runner->prev != NULL)
	{
		printf("%i\n", runner->n);
		runner = runner->prev;
	}
	printf("%i\n", runner->n);
}
