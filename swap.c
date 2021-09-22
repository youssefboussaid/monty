#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: ponter to the list stack
 * @line_number: unused variable
 * Return: the address of the first node
 */
stack_t *swap(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *head;
	int tmp;

	head = *stack;

	if (head != NULL && head->next != NULL)
	{
		tmp = head->n;
		head->n = head->next->n;
		head->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	return (*stack);
}
