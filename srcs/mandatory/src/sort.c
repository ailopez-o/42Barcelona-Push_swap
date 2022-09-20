/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:38:22 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/09/20 00:14:11 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/instructions.h"
#include "../inc/utils.h"
#include "../inc/sort.h"

int	get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

/*
case1 : [2,1,3]->sa->[1,2,3].
case2 : [3,2,1]->sa->[2,3,1]->rra->[1,2,3].
case3 : [3,1,2]->ra->[1,2,3].
case4 : [1,3,2]->sa->[3,1,2]->ra->[1,2,3].
case5 : [2,3,1]->rra->[1,2,3].
*/

void	sort_three_stack_a(t_meta *meta)
{
	t_stack	*stack;
	int		index;

	stack = meta->stack_a;
	index = get_min_index(stack);
	if (stack->index == index + 1 && stack->next->index == index && \
		stack->next->next->index == index + 2)
		sa(meta);
	if (stack->index == index + 2 && stack->next->index == index + 1 && \
		stack->next->next->index == index)
		sa_ra(meta, 1);
	if (stack->index == index + 2 && stack->next->index == index && \
		stack->next->next->index == index + 1)
		ra(meta);
	if (stack->index == index && stack->next->index == index + 2 && \
		stack->next->next->index == index + 1)
		sa_ra(meta, 0);
	if (stack->index == index + 1 && stack->next->index == index + 2 && \
		stack->next->next->index == index)
		rra(meta);
}

/* This function divide the strategy of sorting depends of the number
of items of the Stack A */

void	sort(t_meta *meta)
{
	if (meta->stack_size < 3)
		sa(meta);
	else if (meta->stack_size < 4)
		sort_three_stack_a(meta);
	else if (meta->stack_size < MIN_BLOCK_SIZE)
	{
		pre_sort_slot(meta, 1, (meta->stack_size - 3));
		sort_three_stack_a(meta);
		smart_sort(meta);
	}
	else
		sloted_sort(meta);
}
