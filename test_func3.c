#include "monty.h"

global_var global_variable;

/**
 * mod - get modula of 2 numbers
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int j;
	stack_t *runner;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	runner = (*stack)->next;
	j = runner->n % (*stack)->n;
	runner->n = j;
	runner->prev = NULL;
	free(*stack);
	*stack = runner;
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - print a string from the stop of stack
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = NULL;

	(void)line_number;
	if (stack && *stack)
		runner = *stack;
	while (runner)
	{
		if (runner->n <= 0 || runner->n > 177)
			break;
		printf("%c", runner->n);
		runner = runner->next;
	}
	printf("\n");
}

/**
 * rotl - rotate the stack
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	stack_t *previous = NULL;
	stack_t *bf_previous = NULL;
	int i = 1;

	(void)line_number;
	if (!stack || !(*stack) || (*stack)->next == NULL)
		return;
	runner = *stack;
	while (runner->next)
	{
		bf_previous = previous;
		previous = runner;
		runner = runner->next;
		previous->next = runner->next;
		runner->next = previous;
		previous->prev = runner;
		runner->prev = bf_previous;
		if (bf_previous)
			bf_previous->next = runner;
		runner = previous;
		if (i)
		{
			*stack = (*stack)->prev;
			previous = *stack;
			i = 0;
		}
		else
		{
			previous = bf_previous->next;
		}
	}
}
/**
 * rotr - Top to Down
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bf_curr = NULL;
	stack_t *af_curr = NULL;

	(void) line_number;
	if (!stack || !(*stack) || !(*stack)->next)
		return;
	af_curr = (*stack)->next;
	while (*stack)
	{
		(*stack)->next = bf_curr;
		(*stack)->prev = af_curr;
		bf_curr = *stack;
		*stack = af_curr;
		if (af_curr)
			af_curr = af_curr->next;
	}
	*stack = bf_curr;
}
