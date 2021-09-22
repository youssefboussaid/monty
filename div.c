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

	/* Check if stack is NULL */
	if (!head || !head->next)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	/* Div second node by the first one and strore result in first node */
	result = (head->next->n) / (head->n);
	head->next->n = result;
	pop(stack, 0);

	return (*stack);
}
