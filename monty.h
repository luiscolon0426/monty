#ifndef _GNU_SOURCE
#define _GNU_SOURCE

/*LIBRARIES*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/*STRUCTURES*/




/**
 * struct global - holds the input FILEstream and the buffer
 * @inputf: input FILEstream
 * @tmp: buffer to save line input
 * @mode: switches between queue and stack modes
 */
struct global
{
	FILE *inputf;
	char *tmp;
	int mode;
};

extern struct global glob;

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
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void freedlist(stack_t *head);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void parse_command(stack_t **stack, char *op, unsigned int line_number);
int open_file(char *filename, stack_t **stack);






#endif
