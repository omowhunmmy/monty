#include "monty.h"


void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);


/**
 * monty_rotl - To rotate the top value of the stack_t linked list to the bottom.
 * @stack: Points to the top mode node of the stack_t linked list.
 * @line_number: Current working line number of the Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *bottom;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;


    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;


    top->next->prev = *stack;
    (*stack)->next = top->next;
    bottom->next = top;
    top->next = NULL;
    top->prev = bottom;


    (void)line_number;
}


/**
 * monty_rotr - To rotate the bottom value of the stack_t linked list to the top.
 * @stack: Points to the top mode node of the stack_t linked list.
 * @line_number: Current working line number of the Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *bottom;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;


    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;


    bottom->prev->next = NULL;
    (*stack)->next = bottom;
    bottom->prev = *stack;
    bottom->next = top;
    top->prev = bottom;


    (void)line_number;
}


/**
 * monty_stack - Converts the queue to a stack.
 * @stack: Points to the top mode node of the stack_t linked list.
 * @line_number: Current working line number of the Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = STACK;
    (void)line_number;
}


/**
 * monty_queue - Converts the stack to a queue.
 * @stack: Points to the top mode node of the stack_t linked list.
 * @line_number: Current working line number of the Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = QUEUE;
    (void)line_number;
}
