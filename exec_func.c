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
        int j = 0, i = 0;
	instruction_t func_array[] = {
		{"push", push},
		{"pall", pall},
		{"pall", pall},
	};
	for(j = 0; j < 3; j++)
	{
		if (strcmp(func_array[j].opcode, array[0]) == 0)
		{
			while(1)
			{
				if (array[1][i] == '\0')
                                        break;
				if (!array[1] || (array[1][i] < '0' || array[1][i] > '9'))
					{
						fprintf(stderr, "L%i : usage: push integer", global_variable.line_number);
						exit(EXIT_FAILURE);
					}
				i++;
			}
			global_variable.number = atoi(array[1]);
			func_array[j].f(&(global_variable.stack), global_variable.line_number);
			return;
		}
		else if (j == 3)
		{
			fprintf(stderr, "L%i unknown instruction %s",	\
				global_variable.line_number, array[0]);
			exit(EXIT_FAILURE);
		}
	}
}
