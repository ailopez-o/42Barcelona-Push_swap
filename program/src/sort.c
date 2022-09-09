/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:38:22 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/08/03 21:38:24 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/instructions.h"
#include "../inc/lst_utils.h"
#include "../inc/utils.h"
#include "../inc/sort_utils.h"
#include "../inc/gui.h"
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE  25

void index_list(t_stack *stack)
{

    int     index;
    t_stack *top;
    t_stack *tmp;
    index = 0;

    top = stack;
    while (stack)
    {
        tmp = top;
        while(tmp)
        {
            if (tmp->num < stack->num)
                index++;
            tmp = tmp->next;
        }
        stack->index = index;
        stack = stack->next;
        index = 0;
    }
}

int sort_key_nbr(t_meta *meta, int num_slot, int slot_size)
{
    int key_nbr;
    int r_hold;

    r_hold = 0;
    key_nbr = slot_size * num_slot;
    while (are_values(meta->stack_a, key_nbr))
    {        
        if (meta->stack_a->index < key_nbr)
         {
            if (r_hold == 1)
            {
                rb(meta);
                r_hold = 0; 
            }
            if (meta->stack_a->index < (key_nbr - (slot_size / 2)))
            {
                pb(meta);
                r_hold = 1;
            }
            else
                pb(meta);
         }   
        else
        {
            if (r_hold == 1)
            {
                rr(meta);
                r_hold = 0; 
            }
            else
                ra(meta);
        }
    }
    return (1);
}


int get_pos(t_stack *stack, int index)
{
    int pos;

    pos = 0;
    while(stack->index != index)
    {
        stack = stack->next;
        pos++;
    }
    return(pos);
}

void quick_sort(t_meta *meta, int side)
{
    int index;
    int pos;
    int stack_size;
    t_stack *stack;

    stack = meta->stack_a;
    if (side == STACKB)
        stack = meta->stack_b;
    stack_size = stack_lstsize(stack);        
    while (stack)
    {
        index = get_min_index(stack);
        if (side == STACKB)
            index = get_max_index(stack);
        pos = get_pos(stack, index);
        while (stack->index != index)
            best_rr(meta,stack_size, pos, side);
        stack_size--;
        stack = push_side(meta, side);
    }
}


int chop_sort(t_meta *meta)
{
    int i;
    int slots;
    int slot_size;

    slot_size = 25;
    if (meta->stack_size > 250)
       slot_size = 45;

    slots = (meta->stack_size / slot_size);
    i = 1;
    while (i < slots)
    {
        sort_key_nbr(meta, i, slot_size);
        i++;
    }
    quick_sort(meta, STACKA);
    quick_sort(meta, STACKB);    

    return (1);
}

int sort(t_meta *meta)
{

    if (meta->stack_size < 25)
    {
        quick_sort(meta, STACKA);
        quick_sort(meta, STACKB); 
    }
    else 
        chop_sort(meta);
    return (1);
}
