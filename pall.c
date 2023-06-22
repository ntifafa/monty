#include "monty.h"

/**
 * pall - print all elements of a stack
 * @temp: linked list
 * Return: nothing
*/

void pall(stack_t *temp)
{
	stack_t *current = temp;

	if (current == NULL)
	{
		return;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
