#include "monty.h"

/**
 * loop_func- loop func
 * @line_num: line number
 * @string: buffer
 * @stack: stack
 * @file: file
 * @read_c: int
 * @nbytes: byte number
 * Return: 0
 */

int loop_func(int line_num, char *string, stack_t *stack,
		FILE  *file, ssize_t read_c, size_t nbytes)
{
	char *opcode;

while (read_c != EOF)
{
	token = 1;
	if (string != NULL)
		free(string);
	string = NULL;
	read_c = getline(&string, &nbytes, file);
	if (read_c == -1)
	{
		free(string);
		if (stack != NULL)
			free_stack(&stack);
		fclose(file);
		return (0);
	}
	line_num++;
	if (read_c == 0)
		continue;
	if (read_c == 1)
		continue;
	opcode = strtok(string, " \n");
	if (opcode == NULL)
		continue;
	push_error_handler(line_num, string
		, stack, file, opcode);
	op_func(opcode, &stack, line_num)(&stack, line_num);
}
return (0);
}
