#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack *next;
	int value;
} stack;



void	rr(stack **stack_a,stack **stack_b);
void	rb(stack **stack_b);
void	ra(stack **stack_a);
void	rrr(stack **stack_a, stack **stack_b);
void	rrb(stack **stack_b);
void	rra(stack **stack_a);
void	ss(stack **stack_a, stack **stack_b);
void	sb(stack **stack_b);
void	sa(stack **stack_a);
void	pa(stack **a, stack **b);
void    pb(stack **a, stack **b);
char    *ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int     ft_atoi(const char *str);
int     validation(char *str);
char    *ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);




#endif