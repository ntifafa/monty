#include "monty.h"

/**
 * free_monty_list -  frees a list_t list.
 * @temp: pointer to stack
 * Return: nothing
 */
void free_monty_list(stack_t *temp)
{
	stack_t *current;

	/* Traverse the list and free each node */
	while (temp != NULL)
	{
	current = temp;
	temp = temp->next;
	free(current);
	}
}
