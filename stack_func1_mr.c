#include "monty.h"


/**
 * inc_stack - Adds a node to the stack.
 * @newNode: Pointer to the new node.
 * @line_number: Interger representing the line number of of the opcode.
 */
void inc_stack(stack_t **newNode, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (stackHead == NULL)
	{
		stackHead = *newNode;
		return;
	}
	temp = stackHead;
	stackHead = *newNode;
	stackHead->next = temp;
	temp->prev = stackHead;
}


/**
 * dis_stck - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void dis_stck(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * top_poper - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void top_poper(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		err_hand_2(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * dis_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void dis_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		err_hand_2(6, line_number);
	printf("%d\n", (*stack)->n);
}

