/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sab_pab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:09:42 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/31 18:09:44 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"

int	pa(t_stack **dest, t_stack **org)
{
	t_stack	*stack_orgtop;

	if (*org == NULL)
		return (1);
	stack_orgtop = (*org)->next;
	if (*dest == NULL)
	{
		(*org)->next = NULL;
		*dest = *org;
		*org = stack_orgtop;
	}
	else
	{
		(*org)->next = *dest;
		(*dest)->pre = (*org);
		*dest = *org;
		*org = stack_orgtop;
	}
	return (write(1, "pa\n", 3));
}

int	pb(t_stack **org, t_stack **dest)
{
	t_stack	*stack_orgtop;

	if (*org == NULL)
		return (1);
	stack_orgtop = (*org)->next;
	if (*dest == NULL)
	{
		(*org)->next = NULL;
		*dest = *org;
		*org = stack_orgtop;
	}
	else
	{
		(*org)->next = *dest;
		(*dest)->pre = (*org);
		*dest = *org;
		*org = stack_orgtop;
	}
	return (write(1, "pb\n", 3));
}

int	sa(t_stack *stack)
{
	int	num;

	num = stack->next->num;
	stack->next->num = stack->num;
	stack->num = num;
	return (write(1, "sa\n", 3));
}

int	sb(t_stack *stack)
{
	int	num;

	num = stack->next->num;
	stack->next->num = stack->num;
	stack->num = num;
	return (write(1, "sb\n", 3));
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	return (write(1, "ss\n", 3));
}
