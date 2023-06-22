#include "monty.h"
/**
 * main - entry point
 * @argc: count of args
 * @argv: array of args
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	char line[100], *opcode, *value_str;
	int line_num = 0, value;
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

		opcode = strtok(line, " ");

		if (strcmp(opcode, "push") == 0)
		{
			value_str = strtok(NULL, " ");

			if (value_str == NULL)
			{
				fprintf(stderr, "Error: L%d: usage: push integer\n", line_num);
				return (EXIT_FAILURE);
			}
			value = atoi(value_str);
		
			temp = push(value, temp, line_num);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(temp);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(temp, line_num);
		}
		else if  (strcmp(opcode, "pop") == 0)
		{
			pop(&temp, line_num);
		}
		else if  (strcmp(opcode, "swap") == 0)
		{
			swap(&temp, line_num);
		}
		else if  (strcmp(opcode, "nop") == 0)
		{
			nop();
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&temp, line_num);
		}
		else
		{
			printf("L%d: unknown instruction %s\n", line_num, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free_monty_list(temp);
	fclose(file);
	return (EXIT_SUCCESS);
}
