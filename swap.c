
#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 * @temp: pointer to the top of the stack in doubly linked list
 * @line_num: line number of opcode
 */
void swap(stack_t **temp, int line_num)
{
	stack_t *first = *temp;
	stack_t *second = (*temp)->next;

	if (*temp == NULL || (*temp)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;

	if (first->next != NULL)
		first->next->prev = first;

	*temp = second;
}

