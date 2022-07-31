/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:09:33 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/31 18:09:36 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/lst_utils.h"

int	ra(t_stack *stack)
{
	int	num;

	num = stack->num;
	while (stack)
	{
		if (stack->next == NULL)
			stack->num = num;
		else
			stack->num = stack->next->num;
		stack = stack->next;
	}
	return (write(1, "ra\n", 3));
}

int	rb(t_stack *stack)
{
	int	num;

	num = stack->num;
	while (stack)
	{
		if (stack->next == NULL)
			stack->num = num;
		else
			stack->num = stack->next->num;
		stack = stack->next;
	}
	return (write(1, "ra\n", 3));
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	return (write(1, "rr\n", 3));
}
