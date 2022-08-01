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
#include "../inc/gui.h"

int	pa(t_meta *meta)
{
	t_stack	*stack_orgtop;
	t_stack **org;
	t_stack **dest;

	org = &meta->stack_b;
	dest = &meta->stack_a;
	if (*org == NULL)
		return (1);
	stack_orgtop = (*org)->next;
	if (*dest == NULL)
		(*org)->next = NULL;
	else
	{
		(*org)->next = *dest;
		(*dest)->pre = (*org);
	}
	*dest = *org;
	*org = stack_orgtop;
	if (*org)
		(*org)->pre = NULL;		
	gui(meta, "pa\n");
	return (1);
}

int	pb(t_meta *meta)
{
	t_stack	*stack_orgtop;
	t_stack **org;
	t_stack **dest;

	org = &meta->stack_a;
	dest = &meta->stack_b;
	if (*org == NULL)
		return (1);
	stack_orgtop = (*org)->next;
	if (*dest == NULL)
		(*org)->next = NULL;
	else
	{
		(*org)->next = *dest;
		(*dest)->pre = (*org);
	}
	*dest = *org;
	*org = stack_orgtop;
	if (*org)
		(*org)->pre = NULL;			
	gui(meta, "pb\n");
	return (1);
}

static void	s(t_stack *stack)
{
	int	num;

	if (!stack)
		return;	
	num = stack->next->num;
	stack->next->num = stack->num;
	stack->num = num;
}

int	sa(t_meta *meta)
{
	s(meta->stack_a);
	gui(meta, "sa\n");
	return (1);
}

int	sb(t_meta *meta)
{
	s(meta->stack_b);
	gui(meta, "sb\n");
	return (1);
}

int	ss(t_meta *meta)
{
	s(meta->stack_a);
	s(meta->stack_b);	
	gui(meta, "ss\n");
	return (1);
}
