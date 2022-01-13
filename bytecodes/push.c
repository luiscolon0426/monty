#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;
	char *op;
	char *endptr;
	int num;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		free(stack);
	}

	op = strtok(NULL, " \n$");

	if (op != NULL)
	{
		num = strtol(op, &endptr, 10);
	}

	if (isdigit(new->n))
	{
		printf("L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!glob.mode)
	{
		if (!*stack)
			new->prev = NULL;
		else
		{
			new->prev = *stack;
			new->prev->next = new;
		}
		new->next = NULL;

		new->n = num;
		*stack = new;
	}
	else
	{
		new->n = num;
		new->prev = NULL;
		new->next = NULL;
		if(!*stack)
			*stack = new;
		else
		{
			tmp = *stack;
			while (tmp->prev)
				tmp = tmp->prev;
			new->next = tmp;
			tmp->prev = new;
		}
	}
}



/**
 * push - adds a new element to the stack.
 * @stack: doubly linked list que nos pasan.
 * @line_number: El valor que va dentro del node.
 *
 * Return: el nuevo node que creamos (new_head).
 **/


void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_head = NULL;
	char *op; /*parametro del push*/
	char *endptr;
	int num;

	new_head = malloc(sizeof(stack_t));
	if (new_head == NULL)
	{
		printf("Error: malloc failed\n");
		freedlist(new_head);
		exit(EXIT_FAILURE);
	}




	new_head->n = num;
	new_head->prev = NULL;



	new_head->next = *stack;

	if (new_head->next != NULL)
	{
		(new_head->next)->prev = new_head;
	}

	*stack = new_head;
}
