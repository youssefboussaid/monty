#include "monty.h"

/**
 * push_error_handler - handles push error
 * @line_num: line number
 * @string: buffer
 * @stack: stack
 * @file: file
 * @opcode: operation to preform
 * Return: void
 */

void push_error_handler(int line_num, char *string
	, stack_t *stack, FILE  *file, char *opcode)
{
	char *num_str;
	int n;

n = strcmp(opcode, "push");
if (n == 0)
{
	num_str = strtok(NULL, "\n");
	if (num_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free(string);
		free_stack(&stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	check_digit(num_str, line_num, string, stack, file);
	token = atoi(num_str);
}
}
