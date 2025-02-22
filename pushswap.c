#include "pushswap.h"

void print_stack(stack *s, char *name)
{
	printf("Stack %s: ", name);
	while (s)
	{
		printf("%d ", s->value);
		s = s->next;
	}
	printf("\n");
}

int is_sorted(stack *a)
{
	if (!a)
	return (1);
while (a->next)
{
	if (a->value > a->next->value)
	return (0);
a = a->next;
}
return (1);
}

int is_higher(int value, stack *a)
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

void    sort_3(stack **a)
{
	if (!a)
	return ;
if(is_higher((*a)->value, *a))
ra(a);
else if (is_higher((*a)->next->value, *a))
rra(a);
if (is_sorted(*a) == 0)
sa(a);
}

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

void sort(stack **a, stack **b) 
{
	(void)b;
	int size = stack_size(*a);
	if (is_duplicate(a) == 1) 
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (is_sorted(*a))
	return;
size = stack_size(*a);
if (size == 1)
return;
else if (size == 2)
sa(a);
else if (size == 3)
sort_3(a);
// else if (size > 3)
//     sort_moves(a);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	stack *a = NULL;
	stack *b = NULL;
	int i = 1;
	while (i < ac)
	{
	if (validation(av[i]) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i++;
	}
	char *temp = ft_strdup(av[1]);
	char *new_temp;
	i = 2;
	while (i < ac)
	{
	new_temp = ft_strjoin(temp, " ");
	free(temp);
	temp = new_temp;
	new_temp = ft_strjoin(temp, av[i]);
	free(temp);
	temp = new_temp;
	i++;
	}

	char **str2 = ft_split(temp, ' ');
	free(temp);
	creat_stack_elements(&a, str2);
	free_str_array(str2);
	print_stack(a, "A");
	print_stack(b, "B");

	printf("-------\n");
	sort(&a, &b);

	printf("-------\n");
	print_stack(a, "A");
	print_stack(b, "B");
	free_stacks(&a, &b);
	return 0;
}
