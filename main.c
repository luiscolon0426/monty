#include "monty.h"
#include <stddef.h>
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 **/
int main(int argc, char *argv[])
{
	stack_t **head;
	ssize_t read_line;
	char *line = NULL;
	size_t len;
	FILE *fd;
	char *command;
	unsigned int num = 0;
	char *file;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(file, "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while ((read_line = getline(&line, &len, fd)) != -1)
	{
		command = strtok(line, " ");
		num++;
		if (command)
			parse_command(head, command, num);
	}
	if (line)
		free(line);

	fclose(fd);
	return (0);
}



/**
 * parse_command - takes the command and calls the corresponding function
 * @stack: first node
 * @op: commands
 * @value: line number
 *
 **/
void parse_command(stack_t **stack, char *op, unsigned int value)
{
	int i;

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

	for (i = 0; comm[i].opcode; i++)
		if (strcmp(op, comm[i].opcode) == 0)
		{
			comm[i].f(stack, value);
			return;
		}

	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%i: unkown instructions %s\n", value, op);
		exit(EXIT_FAILURE);
	}
}
