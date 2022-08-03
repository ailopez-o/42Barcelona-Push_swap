#include "../inc/defines.h"
#include "../inc/instructions.h"
#include "../inc/lst_utils.h"
#include "../inc/utils.h"
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
/*

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

*/


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

int are_values(t_stack *stack, int key_nbr)
{
    int exist;

    exist = 0;
    while (stack)
    {
        if (stack->num < key_nbr)
            exist = 1;
        stack = stack->next;
    }
    return (exist);
}

int sort_key_nbr(t_meta *meta, int key_nbr)
{
    while (are_values(meta->stack_a, key_nbr))
    {        
        if (meta->stack_a->num < key_nbr)
            pb(meta);
        else
            ra(meta);
    }
    return (1);
}

int best_rr(t_meta *meta, int index, int stack_size,int side)
{
    if (index > stack_size/2)
    {
        if (side == STACKA)
            rra(meta);
        else
            rrb(meta);
    }
    else
    {
        if (side == STACKA)
            ra(meta);
        else
            rb(meta);
    }
    return (1);
}

t_stack *push_side(t_meta *meta, int side)
{
    if (side == STACKB)
    {
        pa(meta);
        return (meta->stack_b);
    }
    else
    {
        pb(meta);
        return (meta->stack_a);       
    }
}

void quick_sort(t_meta *meta, int side)
{
    int index;
    int value;
    int stack_size;
    t_stack *stack;

    stack = meta->stack_a;
    if (side == STACKB)
        stack = meta->stack_b;
    stack_size = stack_lstsize(stack);        
    while (stack)
    {
        value = get_min(stack);
        if (side == STACKB)
            value = get_max(stack);
        index = get_index(stack, value);
        while (stack->num != value)
            best_rr(meta, index, stack_size, side);
        stack_size--;
        stack = push_side(meta, side);
    }
}


int chop_sort(t_meta *meta)
{
    int key_nbr;
    int size;
    int i;
    int slots;

    slots = (meta->stack_size / 25);
    size = (get_max(meta->stack_a) - get_min(meta->stack_a)) / slots;
    i = 1;
    while (i < slots)
    {
        key_nbr = meta->min + (size * i);
        sort_key_nbr(meta, key_nbr);
        i++;
    }
    quick_sort(meta, STACKA);
    quick_sort(meta, STACKB);    

    return (1);
}

int my_sort(t_meta *meta)
{

    if (meta->stack_size < 10)
    {
        quick_sort(meta, STACKA);
        quick_sort(meta, STACKB); 
    }
    else 
        chop_sort(meta);
    return (1);
}


int sort(t_meta *meta)
{
    my_sort(meta);
    return (1);
}