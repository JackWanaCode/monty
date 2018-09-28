#include "monty.h"

global_var global_variable;

/**
 * push - Pushes an element to the stack
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int i = 0;
	char *num = global_variable.number;

	if (!num)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		printf("c = %c\n i = %i\n", num[i], i);
		if (i != 0 && num[i] == '\0')
			break;
		if (num[i] < '0' || num[i] > '9')
		{
			if (((num[0] != '-' && num[0] != '+') && num[0] == ' ') && num[1] > '9')
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free_list(global_variable.stack);
				fclose(global_variable.file);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(num);
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
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
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
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
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
	stack_t *runner;

	if (!stack || !(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n"
			, line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	runner = (*stack)->next;
	(*stack)->next = runner->next;
	if (runner->next)
		runner->next->prev = (*stack);
	(*stack)->prev = runner->prev;
	runner->prev = NULL;
	runner->next = (*stack);
	*stack = runner;
}
