/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:56:54 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/29 17:56:57 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../lib/libft/libft.h"
#include "../inc/print.h"
#include "../inc/lst_utils.h"

int	rrab(t_stack *stack)
{
	int num;

	stack = stack_lstlast(stack);
	num = stack->num;
	while(stack)
	{
		if (stack->pre == NULL)
			stack->num = num;
		else
			stack->num = stack->pre->num;
		stack = stack->pre;
	}
	return (1);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrab(stack_a);
	rrab(stack_b);
	return (1);
}

int	rab(t_stack *stack)
{
	int num;

	num = stack->num;
	while(stack)
	{
		if (stack->next == NULL)
			stack->num = num;
		else
			stack->num = stack->next->num;
		stack = stack->next;
	}
	return (1);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	rab(stack_a);
	rab(stack_b);
	return (1);	
}

int	sab(t_stack *stack)
{
	int	num;

	num = stack->next->num;
	stack->next->num = stack->num;
	stack->num = num;
	return (1);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	sab(stack_a);
	sab(stack_b);
	return (1);	
}

int	execute(int op, t_stack	*stack_a, t_stack *stack_b)
{
	if (op == SA)
		sab(stack_a);
	if (op == SB)
		sab(stack_b);
	if (op == SS)
		ss(stack_a, stack_b);
	if (op == RA)
		rab(stack_a);
	if (op == RB)
		rab(stack_b);
	if (op == RR)
		rr(stack_a, stack_b);
	if (op == RRA)
		rrab(stack_a);
	if (op == RRB)
		rrab(stack_b);
	if (op == RRR)
		rrr(stack_a, stack_b);				
	print_op(op);
	return (1);
}
