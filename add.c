#include "monty.h"

/**
 * add - remove the top element from the stack
 * @temp: pointer to the top of the stack in doubly linked list
 * @line_num: line number on command line
 */
void add(stack_t **temp, int line_num)
{
	stack_t *first = *temp;
	stack_t *second = (*temp)->next;

	if (*temp == NULL) /* checking if list is empty */
	{
		printf("L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	second->n += first->n;
	*temp = (*temp)->next;

	if (*temp != NULL)
		(*temp)->prev = NULL;
	free(first);
}
