#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t
{
    struct stack_t *next;
    int number;
} stack;

#endif