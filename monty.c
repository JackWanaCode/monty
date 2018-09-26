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
        int i = 0, line_num = 1;
	stack_t *stack = NULL;

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
		if (strcmp(array[0], "push") == 0)
			push(&stack, atoi(array[1]));
		else if (strcmp(array[0], "pall") == 0)
			pall(stack);
		else
		{
			fprintf(stderr, "L%i unknown instruction %s\n",\
				line_num, array[0]);
			exit(EXIT_FAILURE);
		}
		line_num++;
	}
	return (0);
}
