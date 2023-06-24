#include "monty.h"
/**
 * findchar - looks for a character in a strind
 * @value_str: string to be searched
 * @search: character being searched
 * Return: 1 on success or 0 on failure
 */
int findchar(char *value_str, char *search)
{
	int i = 0;
	char *result;

	for (i = 0; i < (int)strlen(search); i++)
	{
		result = strchr(value_str, search[i]);
		if (result != NULL)
			return (1);
	}
	return (0);
}
