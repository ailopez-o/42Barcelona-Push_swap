/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_slot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorlopezdeaudicana <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:07:12 by aitorlope         #+#    #+#             */
/*   Updated: 2022/09/20 01:07:18 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/instructions.h"
#include "../inc/sort_utils.h"
#include "../inc/lst_utils.h"

int	push_b_hold(t_meta *meta)
{
	pb(meta);
	return (1);
}

/* This function iterate the stackA while are values in the Stack
Each value lower than ´key_nbr´ is pushed to stackB.
If the value pushed to stackB is the half-low index of the slot then is rotate 
to put the value at the bottom of the stackB.
If we have to rotate stackB, this movement is on hold to perform ´rr´and avoid 
doing ra&rb.
 */

void	pre_sort_slot(t_meta *meta, int num_slot, int slot_size)
{
	int	key_nbr;
	int	r_hold;

	r_hold = 0;
	key_nbr = slot_size * num_slot;
	while (are_values(meta->stack_a, key_nbr))
	{
		if (meta->stack_a->index < key_nbr)
		{
			if (r_hold == 1)
				r_hold = rb_or_rr(meta, 0);
			if (meta->stack_a->index < (key_nbr - (slot_size / 2)))
				r_hold = push_b_hold (meta);
			else
				pb(meta);
		}
		else
		{
			if (r_hold == 1)
				r_hold = rb_or_rr(meta, 1);
			else
				ra(meta);
		}
	}
}

/* This function check the needed index and if the position is
under the half stack (A or B) rotate in one way or the opposite */

void	best_rr(t_meta *meta, int pos, int side)
{
	int	stack_size;

	if (pos == 0)
		return ;
	stack_size = stack_lstsize(meta->stack_a);
	if (side == STACKB)
		stack_size = stack_lstsize(meta->stack_b);
	if (pos > (stack_size / 2))
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
}

/* This function get the maximun index in stack B
and push to the stack A using the minimun movements possible. 
If trying to find a number, the funcion finds the next index
push both and then swap them in stack A to save future movements
*/

void	smart_sort(t_meta *meta)
{
	int		index;
	int		close_index;
	int		pos;
	int		swap;
	t_stack	*stack;

	stack = meta->stack_b;
	while (stack)
	{
		get_close_index (meta, &index, &close_index, &pos);
		swap = 0;
		while (stack->index != index)
		{
			if (stack->index == close_index)
			swap = push_close_value(meta, &stack, index, &pos);
			best_rr(meta, pos, STACKB);
		}
		stack = push_side(meta, STACKB);
		if (swap)
			sa(meta);
	}
}

/* This function divide stackA un slots of ´slot_size´ items,
Then find the values that belong to this slot and push to stackB. 
In stackB half values (upper ones) of the slots remains in the top and 
the lowers are rotated to the bottom of the stack B
*/

void	sloted_sort(t_meta *meta)
{
	int	i;
	int	slots;
	int	slot_size;

	slot_size = MIN_BLOCK_SIZE;
	if (meta->stack_size > 250)
		slot_size = MAX_BLOCK_SIZE;
	slots = (meta->stack_size / slot_size);
	if (meta->stack_size % slot_size > 0)
		slots ++;
	i = 1;
	while (i <= slots)
	{
		pre_sort_slot(meta, i, slot_size);
		i++;
	}
	smart_sort(meta);
}
