#include "monty.h"
/**
 * swap - swaps the two tops elements of the stack
 * @stack: head of doubly linked list
 * @value: ...
 *
 **/
void swap(stack_t **stack, unsigned int value)
{
	stack_t *tmp;
	(void)value;

	if (!(*stack) || !((*stack)->next))
	{
		printf("L%i: can't swap, stack too short\n", value);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
	}



/**
 * add - adds the two tops elements of the stacks
 * @stack: head of doubly linked list.
 * @value: ...
 *
 * Return: result
 **/
void add(stack_t **stack, unsigned int value)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%i:can't add, stack too short\n", value);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	pop(stack, value);
	(*stack)->n += tmp;
}
