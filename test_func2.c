#include "monty.h"
global_var global_variable;
/**
 * add - Adds the top two elements of the stack
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void add(stack_t **stack, unsigned int line_number)
{
	int j;
	stack_t *runner;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	runner = (*stack)->next;
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
}
