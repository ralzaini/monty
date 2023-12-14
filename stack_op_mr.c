#include "monty.h"

/**
 * nodes_multer - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void nodes_multer(stack_t **stack, unsigned int lineNumber)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_hand_2(8, lineNumber, "mul");

	(*stack) = (*stack)->next;
	total = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_moder - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void nodes_moder(stack_t **stack, unsigned int lineNumber)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err_hand_2(8, lineNumber, "mod");


	if ((*stack)->n == 0)
		err_hand_2(9, lineNumber);
	(*stack) = (*stack)->next;
	total = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

