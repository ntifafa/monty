#include "monty.h"



int main(int argc, char *argv[])
{
	char line[100], *opcode, *value_str;
	int line_num = 0, value;
	FILE *file;
	stack_t *temp = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", argc);
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Failed to open file\n");
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_num++;
		line[strcspn(line, "\n")] = '\0';  /* delete trailing newline character */

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
			if (value == 0 && strcmp(value_str, "0") != 0)
			{
				fprintf(stderr, "Error: L%d: usage: push integer\n", line_num);
				return (EXIT_FAILURE);
			}
			temp = push(value, temp, line_num);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(temp);
		}
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
