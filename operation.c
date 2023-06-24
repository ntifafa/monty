#include "monty.h"
/**
 * operation - switches between the opcodes
 * @line: input lines from file
 * @temp: stack
 * @line_num: line number on command line
 * Return: stack
 */
stack_t *operation(char line[100], stack_t *temp, int line_num)
{
	char *value_str, *opcode;
	int value;
	char *search = "abcdedfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	opcode = strtok(line, " ");
	if (strcmp(opcode, "push") == 0)
	{
		value_str = strtok(NULL, " ");

		if (value_str == NULL || findchar(value_str, search))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		value = atoi(value_str);
		temp = push(value, temp, line_num);
	}
	else if ((strcmp(opcode, "pall") == 0) || (strcmp(opcode, "pint") == 0) ||
			 (strcmp(opcode, "pop") == 0) || (strcmp(opcode, "swap") == 0)
			 || (strcmp(opcode, "nop") == 0))
	{
		part1(temp, opcode, line_num);
	}
	else if ((strcmp(opcode, "add") == 0) || (strcmp(opcode, "sub") == 0) ||
			 (strcmp(opcode, "mul") == 0) || (strcmp(opcode, "div") == 0)
			 || (strcmp(opcode, "mod") == 0))
	{
		part2(temp, opcode, line_num);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
	return (temp);
}

/**
 * part1 - switches between the 1st 5 opcodes
 * @opcode: each opcode
 * @temp: stack
 * @line_num: line number on command line
 * Return:
 */
void part1(stack_t *temp, char *opcode, int line_num)
{
	if (strcmp(opcode, "pall") == 0)
		pall(temp);
	else if (strcmp(opcode, "pint") == 0)
		pint(temp, line_num);
	else if (strcmp(opcode, "pop") == 0)
		pop(&temp, line_num);
	else if (strcmp(opcode, "swap") == 0)
		swap(&temp, line_num);
	else if (strcmp(opcode, "nop") == 0)
		nop();
}

/**
 * part2 - switches between the next 5 opcodes
 * @opcode: each opcode
 * @temp: stack
 * @line_num: line number on command line
 * Return:
 */
void part2(stack_t *temp, char *opcode, int line_num)
{
	if (strcmp(opcode, "add") == 0)
		add(&temp, line_num);
	else if (strcmp(opcode, "sub") == 0)
		sub(&temp, line_num);
	else if (strcmp(opcode, "mul") == 0)
		mul(&temp, line_num);
	else if (strcmp(opcode, "div") == 0)
		divide(&temp, line_num);
	else if (strcmp(opcode, "mod") == 0)
		mod(&temp, line_num);
}
