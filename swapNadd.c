#include "monty.h"
/**
 *
 *
 **/
void swap(stack_t **stack, int value)
{
	int a;
	int b;
	int count;

	while(*stack)
	{
		(*stack) = (*stack)->next;
		count++;
	}

	if (count <= 1)
	{
		printf("L%i: can't swap, stack too short\n", value);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	pop(stack, a);
	b = (*stack)->n;
	pop(stack, b);

	push(stack, a);
	push(stack, b);
}

int add(stack_t **stack, int value)
{
	int result = 0;
	int count;

	while(*stack)
	{
		(*stack) = (*stack)->next;
		count++;
	}

	if (count <= 1)
	{
		printf("L%i:can't add, stack too short\n", value);
		exit(EXIT_FAILURE);
	}

	while (stack)
	{
		result += (*stack)->n;
		(*stack) = (*stack)->next;
	}
	pop(stack, value);
	(*stack)->n = result;

	return (result);
}
