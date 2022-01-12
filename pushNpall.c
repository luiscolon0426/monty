#include "monty.h"
#include <ctype.h>

/**
 * push - adds a new element to the stack.
 * @stack: doubly linked list que nos pasan.
 * @line_number: El valor que va dentro del node.
 *
 * Return: el nuevo node que creamos (new_head).
 **/


void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_head;
	char *op;
	char *endptr;
	int num;

	new_head = malloc(sizeof(stack_t));
	if (new_head == NULL)
	{
		printf("Error: malloc failed\n");
		freedlist(new_head);
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, " \n$");
	num = strtol(op, &endptr, 10);
	new_head->n = num;
	if (isdigit(new_head->n))
	{
		printf("L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_head->prev = NULL;
	new_head->next = *stack;
	if (new_head->next != NULL)
		(new_head->next)->prev = new_head;
	*stack = new_head;
}

/**
 * pall - prints all elements of the stack
 * @stack: stack that needs to be printed
 * @line_number: unused variable.
 *
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;
	(void)line_number;

	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}
