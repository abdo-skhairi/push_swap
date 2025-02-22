#include "pushswap.h"

stack   *find_smallest_node(stack	*a)
{
	int smaller;
	stack	*node;

	if(!a)
		return(NULL);
	smaller = a->value;
	while(a)
	{
		if(smaller > a->value)
		{
			smaller = a->value;
			node = a;
		}
		a = a->next;
	}
	return(node);
}

void	set_price(stack *a, stack *b)
{
    int len_a;
    int len_b;

    if (!a || !b)
        return;
    len_a = stack_size(a);
    len_b = stack_size(b);
	while(b)
	{
		b->price = b->index;
		if(!(b->is_in_first_half))
			b->price = len_b - b->index;
		if(b->is_in_first_half)
			b->price += b->target_node->index;
		else
			b->price += len_a - (b->target_node->index);
		b = b->next;
	}
}

void    set_target(stack *a, stack *b)
{
	stack *curent_in_a;
	stack *target_node;
	long target_num;

	if(!a || !b)
		return;
	while(b)
	{
		curent_in_a = a;
		target_num = 9223372036854775807;
		while(curent_in_a)
		{
			if(curent_in_a->value > b->value && curent_in_a->value < target_num)
			{
				target_num = curent_in_a->value;
				target_node = curent_in_a;
			}
			curent_in_a = curent_in_a->next;
		}
		if(target_num == 9223372036854775807)
			b->target_node = find_smallest_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void  set_index_position(stack *stack)
{
	int i;
	int center;

	if(!stack)
		return;
	i = 0;
	center = stack_size(stack) / 2;
	while(stack)
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

void	set_cheap_node(stack *b)
{
	long	cheap_value;
	stack	*cheap_node;

	cheap_value = 9223372036854775807;
	while(b)
	{
		if (b->price < cheap_value)
		{
			cheap_node = b;
			cheap_value = b->price;
		}
		b = b->next;
	}
	cheap_node->cheap = true;
}

void    set_all_nodes(stack *a, stack *b)
{
    set_index_position(a);
    set_index_position(b);

    set_target(a, b);
    set_price(a, b);
}
