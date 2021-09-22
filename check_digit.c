#include "monty.h"






void check_digit(char *num_str, int line_num, char *string
		, stack_t *stack, FILE  *file)
{
	unsigned int i;

for (i = 0; num_str[i] != '\0'; i++)
{
	if (isdigit(num_str[i]) == 0)
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_num);
	free(string);
	free_stack(&stack);
	fclose(file);
	exit(EXIT_FAILURE);
	}
}
}
