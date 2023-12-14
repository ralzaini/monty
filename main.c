#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Return: Returns 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op_file(argv[1]);
	empty_nodes();
	return (0);
}
