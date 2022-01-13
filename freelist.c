#include "monty.h"
/**
 * freedlist - frees a doubly linked list
 * @head: beginning of list
 *
 **/
void freedlist(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}
