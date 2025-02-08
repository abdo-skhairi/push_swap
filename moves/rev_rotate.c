#include "../pushswap.h"

void rev_rotate(stack **stack1)
{
	if (!(*stack1) || !((*stack1)->next))
		return;

	stack *temp1 = *stack1;
	stack *temp2 = *stack1;

	while (temp2->next->next != NULL) {
		temp2 = temp2->next;
	}

	stack *last = temp2->next;
	temp2->next = NULL;
	last->next = temp1;
	*stack1 = last;
}

void	rra(stack **stack_a)
{
	rev_rotate(stack_a);
}

void	rra(stack **stack_b)
{
	rev_rotate(stack_b);
}

void	rra(stack **stack_a, stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}