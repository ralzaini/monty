#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stackHead;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void op_file(char *fileName);
int pars_line(char *input_buffer, int current_line, int current_format);
void rd_file(FILE *);
int len_at_chars(FILE *);
void get_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void empty_nodes(void);
void dis_stck(stack_t **, unsigned int);
void inc_stack(stack_t **, unsigned int);
void inc_queue(stack_t **, unsigned int);

void fun_caller(op_func, char *, char *, int, int);

void dis_top(stack_t **, unsigned int);
void top_poper(stack_t **, unsigned int);
void noper(stack_t **, unsigned int);
void nodes_swaper(stack_t **, unsigned int);

/*Math operations with nodes*/
void nodes_incrs(stack_t **, unsigned int);
void nodes_suber(stack_t **, unsigned int);
void nodes_diver(stack_t **, unsigned int);
void nodes_multer(stack_t **, unsigned int);
void nodes_moder(stack_t **, unsigned int);

/*String operations*/
void dis_char(stack_t **, unsigned int);
void dis_string(stack_t **, unsigned int);
void rotler(stack_t **, unsigned int);

/*Error hanlding*/
void err_hand(int errorCode, ...);
void err_hand_2(int errorCode, ...);
void err_str(int errorCode, ...);
void rotr_err(stack_t **, unsigned int);

#endif

