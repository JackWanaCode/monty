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
void swap(stack_t ** stack, unsigned int line_number)
{
	stack_t *runner = (*stack)->next; /*runner is second node*/

	if (!stack || !(*stack) || (*stack)->next == NULL)
		fprintf(stderr, "%u: can't swap, stack too short\nEXIT_FAILURE"
			, line_number);
	(*stack)->next = runner->next;/*stk-n goes to tail node*/
	runner->next->prev = (*stack);
	(*stack)->prev = runner->prev;
	runner->prev = NULL;
	runner->next = (*stack);
	*stack = runner;
}
void main(void)
{
	stack_t *head;
	head = NULL;
	push(&head, global_variable++);
	push(&head, global_variable++);
	push(&head, global_variable++);
	pall(&head, 1);
/*	pint(&head, 1);
	pop(&head, 1);
	pall(&head, 1);
	pop(&head, 1);
	pall(&head, 1);
	pop(&head, 1);
*/	swap(&head, 1);
	pall(&head, 1);
}
