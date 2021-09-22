#include "monty.h"

int token = 1;
/**
 * main - reads the bytecode and interprets it
 * @argc : number of arg
 * @argv : array of arg
 * Return : 0 on success
 */

int main(int argc, char **argv)
{
	const char *filename;
	char *string = NULL, *opcode, *num_str;
	size_t nbytes = 1;
	FILE *file;
	unsigned int line_num = 0, i = 0;
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

	while (read_c != EOF)
	{
		token = 1;
		i = 0;
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
		if (strcmp(opcode, "push") == 0)
		{
			num_str = strtok(NULL,  "\n");
			if (num_str == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				free(string);
				free_stack(&stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		for (i = 0; num_str[i] != '\0'; i++)
			{
				if (isdigit(num_str[i]) == 0)
				{
					fprintf(stderr,
						"L%d: usage: push integer\n",
						line_num);
					free(string);
					free_stack(&stack);
					fclose(file);
					exit(EXIT_FAILURE);
				}
			}

			token = atoi(num_str);
		}
		op_func(opcode, &stack, line_num)(&stack, line_num);
	}
	free(string);
	free_stack(&stack);
	fclose(file);

	return (0);
}
