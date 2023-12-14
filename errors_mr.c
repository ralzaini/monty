#include "monty.h"

/**
 * err_hand - Prints appropiate error messages determined by their error code.
 * @errorCode: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void err_hand(int errorCode, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, errorCode);
	if (errorCode == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (errorCode == 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
	}
	else if (errorCode == 3)
	{
		l_num = va_arg(ag, int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
	}
	else if (errorCode == 4)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (errorCode == 5)
	{
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
	}
	va_end(ag);
	empty_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err_hand_2 - handles errors.
 * @errorCode: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void err_hand_2(int errorCode, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, errorCode);
	if (errorCode == 6)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
	}
	else if (errorCode == 7)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
	}
	else if (errorCode == 8)
	{
		l_num = va_arg(ag, unsigned int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
	}
	else if (errorCode == 9)
	{
		fprintf(stderr, "L%d: division by zero\n", va_arg(ag, unsigned int));
	}
	va_end(ag);

	empty_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err_str - handles errors.
 * @errorCode: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void err_str(int errorCode, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, errorCode);
	l_num = va_arg(ag, int);

	if (errorCode == 10)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
	}
	else if (errorCode == 11)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
	}
	va_end(ag);

	empty_nodes();
	exit(EXIT_FAILURE);
}
