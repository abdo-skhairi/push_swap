#include "pushswap.h"

int stack_size(stack *a)
{
	int i = 0;

	while(a)
	{
		i++;
		a = a->next;
	}
	return(i);
}

stack *new_node(int value)
{
	stack *node = (stack *)malloc(sizeof(stack));
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL;
	return node;
}

void creat_stack_elements(stack **a, char **str2)
{
	int i = 0;
	if (str2[i])
	{
		*a = new_node(ft_atoi(str2[i]));
		i++;
	}
	while (str2[i])
	{
		stack *tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node(ft_atoi(str2[i]));
		i++;
	}
}
