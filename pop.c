#include "monty.h"

/**
 * pop - remove the top element from the stack
 * @temp: pointer to the top of the stack in doubly linked list
 * @line_num: line number on command line
 */
void pop(stack_t **temp, int line_num)
{
	stack_t *current = *temp;

	if (*temp == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	*temp = (*temp)->next;

	if (*temp != NULL)
		(*temp)->prev = NULL;
	free(current);
}
