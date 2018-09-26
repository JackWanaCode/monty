#include "monty.h"


/**
 * main - Entry point
 * Description: run the m file
 * Return: 0
 */
int main(int argc, char **argv)
{
	char line[80];
        char *token;
        char array[2][80];
        int i = 0, j = 0;
	unsigned line_number = 1;
	stack_t *stack = NULL;
	instruction_t func_array[] = {
		{"push", push_n},
		{"pall", pall},
	};

	if (argc < 2)
	{
		perror("USAGE: monty file");
                exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		i = 0;
		token = strtok(line, " \n");
		while(token != NULL)
		{
			strcpy(array[i], token);
			token = strtok(NULL, " \n");
			i++;
		}
		for(j = 0; j < 2; j++)
		{
			if (strcmp(func_array[j].opcode, array[0]) == 0)
			{
				if (isdigit(atoi(array[1])) != 0)
				{
					fprintf(stderr, "L%i, usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				if (strcmp(array[0], "pall") == 0)
				{
					func_array[j].f(stack);
				}
				else
				{
					push_n(&stack, atoi(array[1]));
				}
					func_array[j].f(&stack, atoi(array[1]));
 			}
		}
/*		if (j == 2)
		{
			fprintf(stderr, "L%i unknown instruction %s",\
				line_number, array[0]);
			exit(EXIT_FAILURE);
		}
*/		line_number++;
	}
	return (0);
}
