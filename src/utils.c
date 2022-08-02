#include "../inc/defines.h"

int get_max(t_stack *stack)
{
    int max;

    max = stack->num;
    while(stack)
    {
        if (max < stack->num)
            max = stack->num;
        stack = stack->next;
    }
    return(max);
}

int are_negatives(t_stack *stack)
{
    while(stack)
    {
        if (stack->num < 0)
            return(1);
        stack = stack->next;
    }
    return (0);
}

int get_min(t_stack *stack)
{
    int min;

    min = stack->num;
    while(stack)
    {
        if (min > stack->num)
            min = stack->num;
        stack = stack->next;
    }
    return(min);
}

int get_abs(int max, int min)
{
    if (min < 0)
        min = -min;
    if (max < 0)
        max = -max;        

    if (min > max)
        return (min);
    else 
        return (max);
}