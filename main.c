#include "monty.h"
/**
 * main - entry point
 * @argc: count of args
 * @argv: array of args
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	char line[100];
	int line_num = 0;
	FILE *file;
	stack_t *temp = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_num++;
		if (line[0] == '\0' || check_spaces(line))
			continue;
		temp = operation(line, temp, line_num);
	}
	free_monty_list(temp);
	fclose(file);
	return (EXIT_SUCCESS);
}
