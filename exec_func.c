#include "monty.h"

/**
 * exec - Entry point
 * Description: execute opcode function
 * @array: double pointer that point to 2d array
 * Return: no thing
 */
global_var global_variable;
void exec(char (*array)[80])
{
	int j = 0;
	instruction_t func_array[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
	};
	for (j = 0; j < 5; j++)
	{
		if (strcmp(func_array[j].opcode, array[0]) == 0)
		{
			global_variable.number = array[1];
			func_array[j].f(&(global_variable.stack),\
					global_variable.line_number);
			return;
		}
		else if (j == 4)
		{
			fprintf(stderr, "L%i unknown instruction %s\n",\
				global_variable.line_number, array[0]);
			fclose(global_variable.file);
			free_list(global_variable.stack);
			exit(EXIT_FAILURE);
		}
	}
}
