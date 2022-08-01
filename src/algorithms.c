#include "../inc/defines.h"
#include "../inc/instructions.h"
#include "../inc/lst_utils.h"
#include "../inc/gui.h"
#include <stdio.h>
#include <stdlib.h>

int num_max(t_stack *stack)
{
    int nummax;

    nummax = 0;
    while (stack)
    {
        if (stack->num > nummax)
            nummax = stack->num;
        stack = stack->next;
    }
    return (nummax);
}

static int easy_sort(t_meta *meta)
{
    int     nummax;

    while (meta->stack_a)
    {
        nummax = num_max(meta->stack_a);
        while (meta->stack_a->num != nummax)
            rra(meta);
        pb(meta);
    }

    while (meta->stack_b)
        pa(meta);
	return (1);
}

int sort(t_meta *meta)
{
    easy_sort(meta);
    return (1);
}