/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:56:23 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/29 17:56:27 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../../../lib/libft/libft.h"
#include "../inc/lst_utils.h"
#include "../inc/exec_ops.h"
#include "../inc/parser.h"
#include <stddef.h>

void	end_program(char	*str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit (0);
}

void	get_instructions(t_meta *meta)
{
	char	*op;

	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (exec_ops(meta, op) == 0)
		{
			free (op);
			end_program("Error");
		}
		free (op);
		op = get_next_line(STDIN_FILENO);
	}
}

int	main(int argv, char **argc)
{
	t_meta	meta;
	int		sorted;

	if (argv == 1)
		return (0);
	meta.gui = 0;
	meta.print_ops = 1;
	meta.print_stack = 0;
	if (stack_ini(&meta, argc) == 0)
		end_program ("Error");
	index_list(meta.stack_a);
	get_instructions(&meta);
	sorted = stack_is_sorted(meta.stack_a);
	stack_lstfree(&meta.stack_a);
	stack_lstfree(&meta.stack_b);
	if (sorted)
		end_program ("OK");
	else
		end_program ("KO");
	return (0);
}
