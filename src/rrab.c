/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:12:20 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/31 18:12:23 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/lst_utils.h"

int	rra(t_stack *stack)
{
	int	num;

	stack = stack_lstlast(stack);
	num = stack->num;
	while (stack)
	{
		if (stack->pre == NULL)
			stack->num = num;
		else
			stack->num = stack->pre->num;
		stack = stack->pre;
	}
	return (write(1, "rra\n", 4));
}

int	rrb(t_stack *stack)
{
	int	num;

	stack = stack_lstlast(stack);
	num = stack->num;
	while (stack)
	{
		if (stack->pre == NULL)
			stack->num = num;
		else
			stack->num = stack->pre->num;
		stack = stack->pre;
	}
	return (write(1, "rrb\n", 4));
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	return (write(1, "rrr\n", 4));
}
