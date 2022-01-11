#include "monty.h"
/**
 * push - adds a new element to the stack.
 * @stack: doubly linked list que nos pasan.
 * @value: El valor que va dentro del node.
 *
 * Return: el nuevo node que creamos (new_head).
 **/
stack_t *push(stack_t **stack, int value)
{
	stack_t *new_head;

	new_head = malloc(sizeof(stack_t));
	if (new_head == NULL)
	{
		printf("Error: malloc failed\n");
		freedlist(new_head);
		exit(EXIT_FAILURE);
	}
	new_head->n = value;
	new_head->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new_head;
		new_head->next = NULL;
	}
	else
	{
		new_head->next = *stack;
		(*stack)->prev = new_head;
		*stack = new_head;
	}
	return (new_head);
}

/**
 * pall - prints all elements of the stack
 * @stack: stack that needs to be printed
 * @line_number: unused variable.
 *
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		return;

	while (*stack)
	{
		printf("%i\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
