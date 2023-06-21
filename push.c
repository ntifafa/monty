#include "monty.h"

/**
 * push - pushes an element to the stack
 * @val: value to be added
 * @line_num: line number of arg
*/

void push(int val, int line_num)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = temp;
	if (temp != NULL)
	{
		temp->prev = new_node;
	}
	temp = new_node;

	(void)line_num;
}
