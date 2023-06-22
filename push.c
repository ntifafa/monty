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
	/*stack_t *temp = NULL;*/

	if (val > INT_MAX || val < INT_MIN || val == 0)
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
	new_node->prev = NULL;
	new_node->next = temp;
	if (temp != NULL)
	{
		temp->prev = new_node;
	}
	temp = new_node;

	/*(void)line_num;*/
	return (temp);
}
