#include "pushswap.h"
#include <limits.h> // For LONG_MAX


void set_index_position(stack *stack)
{
    int i; 
    int center;

    if (!stack)
        return;

    i = 0;
    center = stack_size(stack) / 2;
    
    while (stack)
    {
        stack->index = i;
        if(i <= center)
            stack->is_in_first_half = true;
        else
            stack->is_in_first_half = false;
        stack = stack->next;
        i++;
    }
}

void set_target(stack *a, stack *b)
{
    stack *current_in_a;
    stack *target_node;
    long target_value;

    if (!a || !b)
    return;

while (b)
{
    current_in_a = a;
    target_value = LONG_MAX;
    
    while (current_in_a)
    {
        if (current_in_a->value > b->value && current_in_a->value < target_value)
        {
            target_value = current_in_a->value;
            target_node = current_in_a;
        }
        current_in_a = current_in_a->next;
    }
    
    if (LONG_MAX == target_value)
    b->target_node = find_smallest_node(a);
    else
    b->target_node = target_node;

    b = b->next;
}
}

void set_price(stack *a, stack *b)
{
    int len_a, len_b;

    len_a = stack_size(a);
    len_b = stack_size(b);
    while (b)
    {
        b->price = b->index;
        if (!(b->is_in_first_half))
            b->price = len_b - b->index;

        if (b->target_node->is_in_first_half)
            b->price += b->target_node->index;
        else
            b->price += len_a - (b->target_node->index);
        b = b->next;
    }
}

void set_cheap_node(stack *b)
{
    long cheap_value = LONG_MAX;
    stack *cheap_node = NULL;
    if (!b)
		return;

	stack *temp = b;
	while(temp)
	{
		temp->cheap = 0;
		temp = temp->next;
	}
    while (b)
    {
        if (b->price < cheap_value)
        {
            cheap_node = b;
            cheap_value = b->price;
        }
        b = b->next;
    }
    if (cheap_node)
        cheap_node->cheap = 1;
}

void set_all_nodes(stack *a, stack *b)
{
    if (!a || !b)
        return;

    set_index_position(a);
    set_index_position(b);
    set_target(a, b);
    set_price(a, b);
    set_cheap_node(b);
}
