#include "monty.h"

/**
 * main - Entry point
 * Description: run the m file
 * Return: 0
 */
int main(int argc, char **argv)
{

	FILE *file = fopen(argv[1], "r");
	char line[80];
	if (!file)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		printf("%s\n", line);
	}
	return (0);
}
