#include "monty.h"


/**
 * main - Entry point
 * Description: run the m file
 * Return: 0
 */
global_var global_variable;

int main(int argc, char **argv)
{
	char line[80];
        char *token;
        char array[2][80];
	int i = 0;

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
	global_variable.line_number = 1;
	global_variable.stack = NULL;
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
		exec(array);
		global_variable.line_number++;
	}
	return (0);
}
