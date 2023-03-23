#include "monty.h"

/**
 * push - function pushes node to top of stack
 * @stack: pointer to the stack
 * @line_number: index line number
 * Return: 0 for success
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));

	new_node->next = *stack;
	new_node->prev = NULL;
	new_node->n = data;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - function prints all the data in stack
 * @stack: pointer to stack
 * @line_number: index line number
 * Return: 0 on success
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *printer;

	printer = *stack;

	while (printer != NULL)
	{
		printf("%d\n", printer->n);
		printer = printer->next;
	}
}

/**
 * pint - prints data at top of the stack
 * @stack: pointer to stack
 * @line_number: index line number
 * Return: 0 on success
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *printer;

	printer = *stack;

	if (printer == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pint, stack empty");
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", printer->n);
}

/**
 * pop - function removes node from the list
 * @stack: pointer to stack
 * @line_number: index line number
 * Return: removed item
 */
void pop(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pop an empty stack");
		exit(EXIT_FAILURE);
	}

	*stack = node->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}
