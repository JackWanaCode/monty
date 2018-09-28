#include "monty.h"

global_var global_variable;

/**
 * push - set queue atribute for push function
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_variable.queue_ask = 1;
}

/**
 * stack - set stack atribute for push function
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_variable.queue_ask = 0;
}
