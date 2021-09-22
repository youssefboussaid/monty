#include "monty.h"
int token = 1;
/**
 * main - reads the bytecode and interprets it
 * @argc : number of arg
 * @argv : array of arg
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	const char *filename;
	char *string = NULL;
	size_t nbytes = 1;
	FILE *file;
	unsigned int line_num = 0;
	ssize_t read_c = 0;
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file <file>");
		exit(EXIT_FAILURE);
	}
	loop_func(line_num, string, stack, file, read_c, nbytes);
	return (0);
}
