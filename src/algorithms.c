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
/*

static int bubble_sort(t_meta *meta)
{
    int i;
    int j;

    i = 0;
    while (i < meta->stack_size)
    {
        j = 0;
        while (j < meta->stack_size)
        {
            rra(meta); 
            if (meta->stack_a->next != NULL && meta->stack_a->num > meta->stack_a->next->num)
                sa(meta);
            j++;
        }
        pb(meta);
        i++;
    }
    while (meta->stack_b)
        pa(meta); 
	return (1);
}

*/

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

int get_index(t_stack *stack, int value)
{
    int pos;

    pos = 0;
    while(stack->num != value)
    {
        stack = stack->next;
        pos++;
    }
    return(pos);
}


int quick_sort_10(t_meta *meta)
{
    int index;
    int min;
    int stack_size;

    stack_size = meta->stack_size;
    while (meta->stack_a)
    {
        min = get_min(meta->stack_a);
        index = get_index(meta->stack_a, min);
        while (meta->stack_a->num != min)
        {
            if (index > stack_size/2)
                rra(meta);
            else
                ra(meta);
        }

        stack_size--;
        pb(meta);
    }
    while (meta->stack_b)
        pa(meta);
    return (1);
}

int quick_sort(t_meta *meta)
{

    if (meta->stack_size < 250)
    {
        quick_sort_10(meta);
    }
    else 
    {

    }
    return (1);
}


int sort(t_meta *meta)
{
    quick_sort(meta);
    return (1);
    easy_sort(meta); 
    return (1);
}