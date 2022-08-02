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
#include "../lib/libft/libft.h"
#include "../lib/miniliblx/minilibx_macos/mlx.h"
#include "../inc/lst_utils.h"
#include "../inc/print.h"
#include "../inc/gui.h"
#include "../inc/utils.h"
#include "../inc/instructions.h"
#include "../inc/algorithms.h"
#include <stddef.h>


int	stack_ini(t_meta *meta, char **values)
{
	int		i;
	t_stack	*new;

	meta->stack_a = NULL;
	meta->stack_b = NULL;
	i = 1;
	while (values[i])
	{
		new = stack_lstnew(ft_atoi(values[i]));
		stack_lstadd_back(&meta->stack_a, new);
		i++;
	}
	meta->stack_size = stack_lstsize(meta->stack_a);
	meta->max = get_max(meta->stack_a);
	meta->min = get_min(meta->stack_a);
	meta->abs = get_abs(meta->min, meta->max);
	meta->neg = are_negatives(meta->stack_a);
	meta->numops = 0;
	return (1);
}

void gui_init(t_meta *meta)
{
	meta->vars.mlx = mlx_init();
	meta->vars.win = mlx_new_window(meta->vars.mlx, WINX, WINY, "push_swap - ailopez-");
	meta->bitmap.img = mlx_new_image(meta->vars.mlx, WINX, WINY);
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
			&meta->bitmap.bitxpixel, &meta->bitmap.lines, &meta->bitmap.endian);
}


void	gui_loop(t_meta *meta)
{
	draw_push_swap(meta);		
	mlx_hook(meta->vars.win, 2, 0, key_press, meta);	
	mlx_hook(meta->vars.win, 17, 0, terminate_program, meta);
	mlx_loop(meta->vars.mlx);
}

void	console(t_meta *meta)
{
	meta->print_ops = 1;
	sort(meta);
	stack_lstfree(&meta->stack_a);
	stack_lstfree(&meta->stack_b);
}


int	main(int argv, char **argc)
{
	t_meta	meta;

	if (argv < 2)
		return (0);
	meta.gui = 0;
	meta.print_ops = 1;
	meta.print_stack = 0;	
	if (!ft_strncmp(argc[1], "-g", 2))
	{
		meta.gui = 1;
		argc++;
		gui_init(&meta);
	}
	stack_ini(&meta, argc);
	if (meta.gui)
		gui_loop(&meta);
	else
		console(&meta);		
	return (0);
}
