#include "monty.h"

/**
 * noper - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void noper(stack_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
}


/**
 * nodes_swaper - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void nodes_swaper(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_hand_2(8, lineNumber, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * nodes_incrs - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void nodes_incrs(stack_t **stack, unsigned int lineNumber)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_hand_2(8, lineNumber, "add");

	(*stack) = (*stack)->next;
	total = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_suber - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void nodes_suber(stack_t **stack, unsigned int lineNumber)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err_hand_2(8, lineNumber, "sub");


	(*stack) = (*stack)->next;
	total = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_diver - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void nodes_diver(stack_t **stack, unsigned int lineNumber)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_hand_2(8, lineNumber, "div");

	if ((*stack)->n == 0)
		err_hand_2(9, lineNumber);
	(*stack) = (*stack)->next;
	total = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

