#include "../pushswap.h"

void swap(stack **stack1)
{
    if (*stack1 == NULL || (*stack1)->next == NULL) 
        return;
    stack *tmp1 = *stack1;
    stack *tmp2 = (*stack1)->next;

    tmp1->next = tmp2->next;
    tmp2->next = tmp1;
    *stack1 = tmp2;
}

void sa(stack **stack_a)
{
    swap(stack_a);
}

void sb(stack **stack_b)
{
    swap(stack_b);
}

void ss(stack **stack_a, stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
}
