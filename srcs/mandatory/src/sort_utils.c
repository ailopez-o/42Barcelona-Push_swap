/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:38:10 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/08/03 21:38:13 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../../../lib/libft/libft.h"
#include "../inc/instructions.h"
#include "../inc/lst_utils.h"

int	rb_or_rr(t_meta *meta, int type_rr)
{
	if (type_rr)
		rr(meta);
	else
		rb(meta);
	return (0);
}

int	get_index(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack->num != value)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	num_max(t_stack *stack)
{
	int	nummax;

	nummax = 0;
	while (stack)
	{
		if (stack->num > nummax)
			nummax = stack->num;
		stack = stack->next;
	}
	return (nummax);
}

t_stack	*push_side(t_meta *meta, int side)
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

int	are_values(t_stack *stack, int key_nbr)
{
	int	exist;

	exist = 0;
	while (stack)
	{
		if (stack->index < key_nbr)
			exist = 1;
		stack = stack->next;
	}
	return (exist);
}
