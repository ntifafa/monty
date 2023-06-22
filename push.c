#include "monty.h"

/**
 * push - pushes an element to the stack
 * @val: value to be added
 * @temp: linked list
 * @line_num: line number of arg
 * Return: a pointer
*/

stack_t *push(int val, stack_t *temp, int line_num)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (val > INT_MAX || val < INT_MIN)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = val;
	if (temp == NULL) /* checking for an empty list */
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		temp = new_node;
	}
	else if (temp != NULL)
	{
		temp->prev = new_node;
		new_node->prev = NULL;
		new_node->next = temp;
	}
	
	temp = new_node;
	return (temp);
}
