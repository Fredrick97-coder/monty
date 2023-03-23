#include "monty.h"

/**
 * _push - function pushes node to top of stack
 * @stack: pointer to the stack
 * @line_number: index line number
 */
void _push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = var_global.push_arg;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - function prints all the data in stack
 * @stack: pointer to stack
 * @line_number: index line number
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
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
 * _pint - prints data at top of the stack
 * @stack: pointer to stack
 * @line_number: index line number
 */
void _pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *printer;

	printer = *stack;
	if (printer == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
		printf("%d\n", printer->n);
}

/**
 * pop - function removes node from the list
 * @stack: pointer to stack
 * @line_number: index line number
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = node->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
