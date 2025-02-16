#include "pushswap.h"

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

void    sort_3(stack **a)
{
    if (!a)
        return ;
    else if((((*a)->value) < ((*a)->next->value) && ((*a)->value) < ((*a)->next->next->value)) && (((*a)->next->value) > ((*a)->next->next->value)))
    {
        rra(a);
        sa(a);
    }
    // else if((((*a)->value) > ((*a)->next->next->value) && ((*a)->value) > ((*a)->next->value)) && (((*a)->next->value) > ((*a)->next->next->value)))
    // {
    //     rra(a);
    //     sa(a);
    // }
    else if((((*a)->value) > ((*a)->next->value) && ((*a)->next->value) < ((*a)->next->next->value)) && (((*a)->next->value) < ((*a)->value)))
        sa(a);
}

void    sort_4(stack **a)
{
    if (!a)
        return ;
}

// int     is_dublication(stack *a)
// {
//     int i;

//     i = a->value;
//     while(a)
//     {
//         if((a->next->value) == i)
//             return(1);
//         a = a->next;
//     }
//     return(0);
// }

void    sort_all(stack **a, stack **b)
{
    (void)b;
    if(is_sorted(*a) == 1)
        return;
    // else if(is_dublication(*a) == 1)
    // {
    //     write(2, "Error\n", 6);
    //     exit(1);
    // }
    else if (stack_size(*a) == 1)
        return;
    else if(stack_size(*a) == 2)
        sa(a);
    else if(stack_size(*a) == 3)
        sort_3(a);
    else if(stack_size(*a) == 4)
        sort_4(a);
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

	// pb(&a, &b);
	// pb(&a, &b);
	// ss(&a, &b);
    printf("-------\n");
    sort_all(&a, &b);
    printf("-------\n");
	print_stack(a, "A");
	print_stack(b, "B");
    return 0;
}
