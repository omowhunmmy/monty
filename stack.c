#include "monty.h"
#include <string.h>


void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);


/**
 * free_stack - Frees the stack_t stack.
 * @stack: points to the top (stack) or
 *         bottom (queue) of the stack_t.
 */
void free_stack(stack_t **stack)
{
    stack_t *tmp = *stack;


    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}


/**
 * init_stack - Initializes the stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: points to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
    stack_t *s;


    s = malloc(sizeof(stack_t));
    if (s == NULL)
        return (malloc_error());


    s->n = STACK;
    s->prev = NULL;
    s->next = NULL;


    *stack = s;


    return (EXIT_SUCCESS);
}


/**
 * check_mode - to check if the stack_t linked list is in stack or queue mode.
 * @stack: points to the top (stack) or bottom (queue)
 *         of the stack_t linked list.
 *
 * Return: If a stack_t is in stack mode - STACK (0).
 *         If a stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
    if (stack->n == STACK)
        return (STACK);
    else if (stack->n == QUEUE)
        return (QUEUE);
    return (2);
}
