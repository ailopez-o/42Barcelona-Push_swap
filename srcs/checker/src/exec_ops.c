/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorlopezdeaudicana <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:22:37 by aitorlope         #+#    #+#             */
/*   Updated: 2022/09/22 10:22:40 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../lib/libft/libft.h"
#include "../inc/defines.h"
#include "../inc/instructions.h"

int	exec_rotate(t_meta *meta, char *op)
{
	if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(meta);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(meta);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(meta);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(meta);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(meta);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(meta);
	else
		return (0);
	return (1);
}

int	exec_push(t_meta *meta, char *op)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(meta);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(meta);
	else
		return (0);
	return (1);
}

int	exec_swap(t_meta *meta, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(meta);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(meta);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(meta);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(meta);
	else
		return (0);
	return (1);
}

int	exec_ops(t_meta *meta, char *op)
{
	if (exec_swap(meta, op))
		return (1);
	if (exec_push(meta, op))
		return (1);
	if (exec_rotate(meta, op))
		return (1);
	return (0);
}
