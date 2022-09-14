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


int search_closest_value(t_meta *meta, int key_nbr)
{
    t_stack *stack;
    int     num_moves_r;
    int     stack_size;

    num_moves_r = 0;
    stack = meta->stack_a;
    stack_size = stack_lstsize(stack); 
    while (stack)
    {
        if (stack->index <= key_nbr)
            break;
        num_moves_r ++;
        stack = stack->next; 
    }

    if (num_moves_r > (stack_size / 2))
        return (1);
    else
        return (0);
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
    int close_index;
    int pos;
    int swap;
    t_stack *stack;

    stack = meta->stack_a;
    if (side == STACKB)
        stack = meta->stack_b;     
    while (stack)
    {
        // Busco el Index más bajo/alto en el stack
        index = get_min_index(stack);
        close_index = index + 1;
        if (side == STACKB)
        {
            index = get_max_index(stack);
            close_index = index - 1;
        }
        // Busco la posicion en la que se encuantra
        pos = get_pos(stack, index);
        // Mientras que no enconremos, rotamos de la manera más eficiente
        swap = 0;
        while (stack->index != index)
        {
           // detectamos si por el camino enconramos el index consecutivo al buscado
            if (stack->index == close_index)
            {
                swap = 1;
                stack = push_side(meta, side);
                printf("optimicing\n");
                pos = get_pos(stack, index);
            }        
            best_rr(meta, pos, side);
        }
        stack = push_side(meta, side);
        if (swap == 1)
        {   
            swap = 0;
            if (side == STACKA)
                sb(meta);
            if (side == STACKB)
                sa(meta);
        }
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
