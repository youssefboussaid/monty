#include "monty.h"

/**
 * pop - This function deletes the node at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the file
 * Return: Pointer to the stack
 */

stack_t *pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(head);

	if (*stack)
		(*stack)->prev = NULL;

	return (*stack);
}
