#include "../pushswap.h"

void	rotate(stack **stack1)
{
	stack *temp1;
	stack *temp2;

	if(!(*stack1) || !((*stack1)->next))
		return;
	temp1 = *stack1;
	while((*stack1)->next)
	{
		*stack1 = (*stack1)->next;	
	}
	temp2 = *stack1;
	*stack1 = temp1->next;
	temp2->next = temp1;
	temp1->next = NULL;
}

void	ra(stack **stack_a)
{
	rotate(stack_a);
}
void	rb(stack **stack_b)
{
	rotate(stack_b);
}

void	rr(stack **stack_a,stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
