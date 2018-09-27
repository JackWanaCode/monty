#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
global_var global_variable;
void add(stack_t **stack, unsigned int line_number)
{
	int j;
	stack_t *runner = (*stack)->next;

	if ((*stack)->next == NULL || (*stack) == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	j = (*stack)->n + runner->n;
	runner->n = j;
	runner->prev = NULL;
	free(*stack);
	*stack = runner;
}

/**
 * nop - Does nothing
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) (*stack);
	(void) line_number;
	return;
}
