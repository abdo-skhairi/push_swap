#include "pushswap.h"

static void swap(stack **stack1)
{
    if (*stack1 == NULL || (*stack1)->next == NULL) 
        return;

    stack *first = *stack1;
    stack *second = (*stack1)->next;

    first->next = second->next;
    second->next = first;
    *stack1 = second;
}

void sa(stack **stack_a)
{
    swap(stack_a);
    printf("sa\n");
}

void sb(stack **stack_b)
{
    swap(stack_b);
    printf("sb\n");
}

void ss(stack **stack_a, stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}

