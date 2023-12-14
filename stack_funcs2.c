#include "monty.h"
stack_t *stackHead = NULL;

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err_hand(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * empty_nodes - Frees nodes in the stack.
 */
void empty_nodes(void)
{
	stack_t *temp;

	if (stackHead == NULL)
		return;

	while (stackHead != NULL)
	{
		temp = stackHead;
		stackHead = stackHead->next;
		free(temp);
	}
}


/**
 * inc_queue - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @line_number: line number of the opcode.
 */
void inc_queue(stack_t **newNode, unsigned int line_number)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *newNode;
	(*newNode)->prev = temp;

}

