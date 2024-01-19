#include "monty.h"


void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);


/**
 * monty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: To point to the top mode node of the stack_t linked list.
 * @line_number: Current working line number of the Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}


/**
 * monty_pchar - To print the character in the top value
 *               node of the stack_t linked list.
 * @stack: To point to the top mode node of the stack_t linked list.
 * @line_number: Current working line number of the Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pchar_error(line_number, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        set_op_tok_error(pchar_error(line_number,
                         "value out of range"));
        return;
    }


    printf("%c\n", (*stack)->next->n);
}


/**
 * monty_pstr - To print the string contained in the stack_t linked list.
 * @stack: To point to the top mode node of the stack_t linked list.
 * @line_number: Current working line number of the Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;


    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
    {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }


    printf("\n");


    (void)line_number;
}
