#include "pushswap.h"

void free_str_array(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void free_stacks(stack **a, stack **b)
{
    if (a) 
	{
        stack *current = *a;
        stack *next;
        while (current) 
		{
            next = current->next;
            free(current);
            current = next;
        }
        *a = NULL;
    }
    if (b) 
	{
        stack *current = *b;
        stack *next;
        while (current) 
		{
            next = current->next;
            free(current);
            current = next;
        }
        *b = NULL;
    }
}
