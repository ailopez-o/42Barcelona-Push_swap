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
#include "../inc/instructions.h"
#include "../inc/parser.h"
#include <stddef.h>

void	error(char	*str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit (0);
}

int	main(int argv, char **argc)
{
	t_meta	meta;

	if (argv == 1)
		return (0);
	meta.gui = 0;
	meta.print_ops = 1;
	meta.print_stack = 0;
	if (stack_ini(&meta, argc) == 0)
		error ("Error");
	if (stack_is_sorted(meta.stack_a))
		return (0);
	index_list(meta.stack_a);
	stack_lstfree(&meta.stack_a);
	stack_lstfree(&meta.stack_b);	
	return (0);
}
