#include "monty.h"

/**
 * op_file - opens a file
 * @fileName: the file namepath
 * Return: void
 */

void op_file(char *fileName)
{
	FILE *file_d = fopen(fileName, "r");

	if (fileName == NULL || file_d == NULL)
		err_hand(2, fileName);

	rd_file(file_d);
	fclose(file_d);
}


/**
 * rd_file - reads a file
 * @file_d: pointer to file descriptor
 * Return: void
 */

void rd_file(FILE *file_d)
{
	int current_line = 1, format = 0;
	char *line_buffer = NULL;
	size_t buffer_size = 0;

	while (getline(&line_buffer, &buffer_size, file_d) != -1)
	{
		format = pars_line(line_buffer, current_line, format);
		current_line++;
	}
	free(line_buffer);
}


/**
 * pars_line - Separates each line into tokens to determine
 * which function to call
 * @input_buffer: The line from the file to be parsed.
 * @current_line: The line number.
 * @current_format:  The current storage format:
 * If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int pars_line(char *input_buffer, int current_line, int current_format)
{
	char *instruction, *argument;
	const char *delimiter = "\n ";

	if (input_buffer == NULL)
	{
		err_hand(4);
	}
	instruction = strtok(input_buffer, delimiter);
	if (instruction == NULL)
	{
		return (current_format);
	}
	argument = strtok(NULL, delimiter);
	if (strcmp(instruction, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(instruction, "queue") == 0)
	{
		return (1);
	}
	get_func(instruction, argument, current_line, current_format);
	return (current_format);
}

/**
 * get_func - find the appropriate function for the opcode
 * @opcode: instruction
 * @argument: argument of instruction
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_number: The current line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void get_func(char *opcode, char *argument, int line_number, int format)
{
	int i;
	int found_match;

	instruction_t func_list[] = {
		{"push", inc_stack}, {"pall", dis_stck},
		{"pint", dis_top}, {"pop", top_poper},
		{"nop", noper}, {"swap", nodes_swaper},
		{"add", nodes_incrs}, {"sub", nodes_suber},
		{"div", nodes_diver}, {"mul", nodes_multer},
		{"mod", nodes_moder}, {"pchar", dis_char},
		{"pstr", dis_string}, {"rotler", rotler},
		{"rotr", rotr_err}, {NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (found_match = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			fun_caller(func_list[i].f, opcode, argument, line_number, format);
			found_match = 0;
		}
	}
	if (found_match == 1)
		err_hand(3, line_number, opcode);
}


/**
 * fun_caller - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @inst: string representing the instruction.
 * @value: string representing a numeric value.
 * @line_no: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void fun_caller(op_func func, char *inst, char *value, int line_no, int format)
{
	stack_t *node;
	int match_found;
	int i = 0;

	match_found = 1;
	if (strcmp(inst, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			match_found = -1;
		}
		if (value == NULL)
			err_hand(5, line_no);
		while (value[i] != '\0')
		{
			if (isdigit(value[i]) == 0)
				err_hand(5, line_no);
			i++;
		}
		node = create_node(atoi(value) * match_found);
		if (format == 0)
			func(&node, line_no);
		if (format == 1)
			inc_queue(&node, line_no);
	}
	else
		func(&stackHead, line_no);
}
