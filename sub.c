#include "monty.h"

/**
 * sub - This function subtracts the top two nodes of the stack, stores it in
 * the second node, and pops off the top node
 * @stack: The stack list
 * @line_number: The line number of the file
 * Return: The edited stack
 */

stack_t *sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	diff = (head->next->n) - (head->n);
	head->next->n = diff;
	pop(stack, 0);

	return (*stack);
}
