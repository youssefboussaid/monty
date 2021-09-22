#include "monty.h"

/**
 * add - This function adds the top two nodes of the stack, stores it in
 * the second node, and pops off the top node
 * @stack: The stack list
 * @line_number: The line number of the file
 * Return: The edited stack
 */

stack_t *add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = (head->n) + (head->next->n);
	head->next->n = sum;
	pop(stack, 0);

	return (*stack);
}
