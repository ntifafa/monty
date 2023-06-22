#include "monty.h"

/** 
 * check_spaces - checks if the user input only spaces.
 * @line: The pointer to input string.
 * Return: 1 on success, 0 on failure
 */

int check_spaces(char *line)
{
	int i = 0;

	line[strlen(line) - 1] = '\0';
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (0);
		i++;

	}
	return (1);
}