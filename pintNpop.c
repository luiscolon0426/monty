#include "monty.h"
/**
 * pint - prints a value at the top of the stack
 * @stack: doubly linked list
 * @value:
 *
 **/
void pint(stack_t **stack, unsigned int value)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%i: can't pint, stack empty\n", value);
			exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of th stack
 * @stack: head of the doubly linked list
 * @value: ...
 *
 **/
void pop(stack_t **stack, unsigned int value)
{
	stack_t  *tmp;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", value);
		freedlist(*stack);
		exit(EXIT_FAILURE);
	}
	
	tmp = *stack;
	
	if (tmp->next != NULL)
	{
		(*stack) = tmp->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
