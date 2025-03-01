#include "pushswap.h"

int is_duplicate(stack **a)
{
	if (a == NULL || *a == NULL)
		return 0;

	stack *first = *a;
	stack *second;

	while (first != NULL) 
	{
		second = first->next;
		while (second != NULL) 
		{
			if (first->value == second->value) 
				return 1;
		second = second->next;
		}
	first = first->next;
	}
	return 0;
}

int is_sorted(stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int is_higher(int value ,stack *a)
{
	a = a->next;
	while(a)
	{
		if(value < a->value)
			return (0);
	a = a->next;
	}
	return(1);
}

// corect
stack *find_cheapest(stack *b)
{
	if(!b)
		return NULL;
	while(b)
	{
		if(b->cheap == 1)
			return(b);
		b = b->next;
	}
    return NULL;
}


// corect
stack *find_smallest_node(stack *a)
{
    stack *smallest = a;

    if (!a)
        return NULL;

    while (a)
    {
        if (a->value < smallest->value)
            smallest = a;
        a = a->next;
    }

    return smallest;
}
