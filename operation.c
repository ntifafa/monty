#include "monty.h"

void operation(char *opcode, char *value_str, int value,
 stack_t *temp, char line[100], int line_num){
		opcode = strtok(line, " ");
		if (strcmp(opcode, "push") == 0)
		{
			value_str = strtok(NULL, " ");

			if (value_str == NULL)
			{
				fprintf(stderr, "Error: L%d: usage: push integer\n", line_num);
				exit (EXIT_FAILURE);
			}
			value = atoi(value_str);
			if (value == 0 && strcmp(value_str, "0") != 0)
			{
				fprintf(stderr, "Error: L%d: usage: push integer\n", line_num);
				exit (EXIT_FAILURE);
			}
			temp = push(value, temp, line_num);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(temp);
		}

}
