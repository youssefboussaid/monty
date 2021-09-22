#include "monty.h"

/**
 * div_op - This function divides the second top nodes of the stack by the top
 * @stack: The stack list
 * @line_num: The line number of the file
 * Return: The edited stack
 */

stack_t *div_op(stack_t **stack, unsigned int line_num)
{
	int result = 0;
	stack_t *head = *stack;

	if (!head || !head->nex)
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	result = (head->next->n) / (head->n);
	head->next->n = result;
	pop(stack, 0);

	return (*stack);
}
