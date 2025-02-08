#include "../pushswap.h"

void push(stack **stack1, stack **stack2)
{
    stack *tmp;
    tmp = *stack1;
    *stack1 = (*stack1)->next;

    tmp-> next = *stack2;
    *stack2 = tmp;
}

void    pb(stack **a, stack **b)
{
    push(a, b);
}

void    pa(stack **a, stack **b)
{
    push(b, a);
}
