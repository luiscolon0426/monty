#include "monty.h"
/**
 *
 *
 *
 *
 **/
int main(int argc, char *argv[])
{
	instruction_t comm[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
}
