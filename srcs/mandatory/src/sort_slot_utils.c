/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_slot_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorlopezdeaudicana <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:00:01 by aitorlope         #+#    #+#             */
/*   Updated: 2022/09/20 01:00:04 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include "../inc/sort_utils.h"

static int	get_pos(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack->index != index)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

void	get_close_index(t_meta *meta, int *index, int *close_index, int *pos)
{
	*index = get_max_index(meta->stack_b);
	*close_index = *index - 1;
	*pos = get_pos(meta->stack_b, *index);
}

int	is_close_index(t_stack *stack, t_meta *meta, int close_index, int *pos)
{
	if (stack->index == close_index)
	{
		stack = push_side(meta, STACKB);
		*pos = *pos - 1;
		return (1);
	}
	return (0);
}

int	push_close_value(t_meta *meta, t_stack **stack, int index, int *pos)
{
	*stack = push_side(meta, STACKB);
	*pos = get_pos(*stack, index);
	return (1);
}
