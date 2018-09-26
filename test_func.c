#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
global_var global_variable;
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;
	if (stack == NULL)
		printf("ERROR");
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		printf("ERROR");
	new->n = global_variable.number;
	new->next = (*stack);
	new->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new;
	(*stack) = new;
}
/**
 * pall - Prints All values on stack from top down
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
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
/**
 * pint - Prints value at the top of the stack + newline
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (stack == NULL)
		printf("ERROR");
	printf("%i\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stk = NULL;

	(void) line_number;
	if (!stack || !(*stack))
		printf("ERROR");
	new_stk = (*stack);
	(*stack) = (*stack)->next;
	free(new_stk);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = (*stack)->next; /*runner is second node*/

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "%u: can't swap, stack too short\n"
			, line_number);
		perror("EXIT_FAILURE\n");
	}
	(*stack)->next = runner->next;/*stk-n goes to tail node*/
	runner->next->prev = (*stack);
	(*stack)->prev = runner->prev;
	runner->prev = NULL;
	runner->next = (*stack);
	*stack = runner;
	pall(stack, line_number);
}
