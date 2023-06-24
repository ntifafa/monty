#include "monty.h"

/**
 * divide - ivides the second top element of the stack by the top element
 * @temp: pointer to the top of the stack in doubly linked list
 * @line_num: line number on command line
 */
void divide(stack_t **temp, int line_num)
{
	stack_t *first = *temp;
	stack_t *second;

	/* checking if list is empty */
	if (*temp == NULL || (*temp != NULL && (*temp)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	second = (*temp)->next;
	second->n /= first->n;
	*temp = (*temp)->next;

	if (*temp != NULL)
		(*temp)->prev = NULL;
	free(first);
}
