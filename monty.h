#ifndef MONTY_H
#define MONTY_H

/*LIBRARIES*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/*STRUCTURES*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;




/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;




/*PROTOTYPES*/
void push(stack_t **stack, unsigned int value);
void pall(stack_t **stack, unsigned int value);
void freedlist(stack_t *head);
void pint(stack_t **stack, unsigned int value);
void pop(stack_t **stack, unsigned int value);
void add(stack_t **stack, unsigned int value);
void swap(stack_t **stack, unsigned int value);
void nop(stack_t **stack, unsigned int value);
void parse_command(stack_t **stack, char *op, unsigned int value);



int _isdigit(int c);



#endif
