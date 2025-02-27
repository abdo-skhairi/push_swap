#include "pushswap.h"

void    sort_3(stack **a)
{
	if (!a)
		return;
if(is_higher((*a)->value, *a))
	ra(a);
else if (is_higher((*a)->next->value, *a))
	rra(a);
if (is_sorted(*a) == 0)
	sa(a);
}

void rotate_both(stack **a, stack **b, stack *cheapest_node)
{
    while (*b != cheapest_node && *a != cheapest_node->target_node)
        rr(a, b);
    
    set_index_position(*a);
    set_index_position(*b);
}

void reverse_rotate_both(stack **a, stack **b, stack *cheapest_node)
{
    while (*b != cheapest_node && *a != cheapest_node->target_node)
        rrr(a, b);
    
    set_index_position(*a);
    set_index_position(*b);
}

void finish_rotation(stack **current_stack, stack *cheapest_node, char stack_name)
{
    while (*current_stack != cheapest_node)
    {
        if (stack_name == 'a')
        {
            if (cheapest_node->is_in_first_half)
                ra(current_stack);
            else
                rra(current_stack);
        }
        else if (stack_name == 'b')
        {
                if (cheapest_node->is_in_first_half)
                    rb(current_stack);
                else
                    rrb(current_stack);
        }
    }
}

void moves(stack **a, stack **b)
{
    stack *cheapest_node = find_cheapest(*b);

    if (cheapest_node->is_in_first_half && cheapest_node->target_node->is_in_first_half)
		rotate_both(a, b, cheapest_node);
	if (!(cheapest_node->is_in_first_half) && !(cheapest_node->target_node->is_in_first_half))
		reverse_rotate_both(a, b, cheapest_node);
    finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');

    pa(a, b);
}

void    sort_all_moves(stack **a, stack **b)
{
	stack	*small_node;

	// if(stack_size(*a) == 5)
	// 	return;
	// 	sort_5(a);
	if ((stack_size(*a) > 3))
	{
        while(stack_size(*a) > 3)
		{
            pb(a, b);
		}
	}
	sort_3(a);
	while(*b)
	{
        set_all_nodes(*a, *b);
		moves(a, b);
	}
	set_index_position(*a);
	small_node = find_smallest_node(*a);
	if((*a)->is_in_first_half == true)
	{
		while(*a != small_node)
			ra(a);
	}
	else
	{
		while(*a != small_node)
			rra(a);
	}
}
