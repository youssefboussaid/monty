#include "monty.h"

/**
 * mul_op - multiplies the second top element of the stack with the top one
 * @stack: The stack list
 * @line_num: The line number of the file
 * Return: The edited stack
 */

stack_t *mul_op(stack_t **stack, unsigned int line_num)
{
	int result = 0;
	stack_t *head = *stack;

	/* Check if stack is NULL */
	if (!head || !head->next)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	result = (head->next->n) * (head->n);
	head->next->n = result;
	pop(stack, 0);

	return (*stack);
}
