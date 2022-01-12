#include "monty.h"
/**
 * swap - swaps the two tops elements of the stack
 * @stack: head of doubly linked list
 * @value: ...
 *
 **/
void swap(stack_t **stack, unsigned int value)
{
	int a;
	int b;
	int count;

	while (*stack)
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



/**
 * add - adds the two tops elements of the stacks
 * @stack: head of doubly linked list.
 * @value: ...
 *
 * Return: result
 **/
void add(stack_t **stack, unsigned int value)
{
	int result = 0;
	int count;

	while (*stack)
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

}
