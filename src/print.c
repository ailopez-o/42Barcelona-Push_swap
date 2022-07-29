/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:46:10 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/29 20:46:14 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/lst_utils.h"
#include "../lib/libft/libft.h"

int	print_op(int op)
{
	if (op == SA)
		ft_putstr_fd("[sa]\n", 1);
	if (op == SB)
		ft_putstr_fd("[sb]\n", 1);
	if (op == SS)
		ft_putstr_fd("[ss]\n", 1);
	if (op == PA)
		ft_putstr_fd("[pa]\n", 1);
	if (op == PB)
		ft_putstr_fd("[pb]\n", 1);
	if (op == RA)
		ft_putstr_fd("[ra]\n", 1);
	if (op == RB)
		ft_putstr_fd("[rb]\n", 1);
	if (op == RR)
		ft_putstr_fd("[rr]\n", 1);		
	if (op == RRA)
		ft_putstr_fd("[rra]\n", 1);	
	if (op == RRB)
		ft_putstr_fd("[rrb]\n", 1);
	if (op == RRR)
		ft_putstr_fd("[rrr]\n", 1);
	return (1);
}

void	print_row(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;

	str = ft_strdup(" ");
	if (stack_a)
		str = ft_itoa(stack_a->num);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(" ", 1);	
	str = ft_strdup(" ");
	if (stack_b)
		str = ft_itoa(stack_b->num);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{	
	ft_putstr_fd("\n////////\n", 1);	
	while (stack_a || stack_b)
	{
		print_row(stack_a, stack_b);
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	ft_putstr_fd("- -\n", 1);
	ft_putstr_fd("a b\n", 1);
	ft_putstr_fd("////////\n\n", 1);		
}
