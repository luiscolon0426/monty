#include "monty.h"

/**
 * _isdigit - Checks for a digit (0-9).
 * @c: The number to be checked.
 *
 * Return: 1 if the number is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);

}


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

	if (!_isdigit(value))
	{
		printf("L%i: usage: push integer\n", value);
	}

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
void pall(stack_t **stack, unsigned int value)
{
	(void)value;

	if (*stack == NULL)
		return;

	while (*stack)
	{
		printf("%i\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
