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
#include "../inc/lst_utils.h"
#include "../inc/print.h"
#include "../inc/gui.h"
#include "../inc/instructions.h"
#include "../lib/miniliblx/minilibx_macos/mlx.h"
#include <stddef.h>

int	short_stack(t_stack *stack_a, t_stack **stack_b)
{
	t_stack	*new;

	while (stack_a)
	{
		new = stack_lstnew(stack_a->num);
		stack_lstadd_back(stack_b, new);
		stack_a = stack_a->next;
	}
	return (1);
}

int	fill_stack(t_stack **stack, char **values)
{
	int		i;
	t_stack	*new;

	i = 1;
	while (values[i])
	{
		new = stack_lstnew(ft_atoi(values[i]));
		stack_lstadd_back(stack, new);
		i++;
	}
	return (1);
}

int	main(int argv, char **argc)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_meta	meta;
	int		gui;


	if (argv < 2)
		return (0);
	gui = 0;
	if (!ft_strncmp(argc[1], "-g", 2))
	{
		gui = 1;
		argc++;
		meta.vars.mlx = mlx_init();
		meta.vars.win = mlx_new_window(meta.vars.mlx, WINX, WINY, "push_swap - ailopez-");
		meta.bitmap.img = mlx_new_image(meta.vars.mlx, WINX, WINY);
		meta.bitmap.buffer = mlx_get_data_addr(meta.bitmap.img, \
			&meta.bitmap.bitxpixel, &meta.bitmap.lines, &meta.bitmap.endian);
		generate_background(&meta, CARBON);
		draw_push_swap(&meta);
	}

	stack_a = NULL;
	stack_b = NULL;
	fill_stack(&stack_a, argc);
	short_stack(stack_a, &stack_b);
	print_stack(stack_a, stack_b);

/*
	start.axis[X] = 0;
	start.axis[Y] = WINY/4;
	start.color = AZUL;
	end.axis[X] = WINX/4;
	end.axis[Y] = WINY/4;
	end.color = FUCSIA;
	draw_bar(&meta, start, end, 20);
	draw_push_swap(&meta);
*/


	if (gui)
	{
		draw_stack_a(stack_a, &meta);
		mlx_hook(meta.vars.win, 2, 0, key_press, &meta);	
		mlx_hook(meta.vars.win, 17, 0, terminate_program, &meta);
		mlx_loop(meta.vars.mlx);
	}	
	/*
	sa(stack_a);
	print_stack(stack_a, stack_b);
	sb(stack_b);
	print_stack(stack_a, stack_b);
	ss(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	ra(stack_a);
	print_stack(stack_a, stack_b);
	rb(stack_b);
	print_stack(stack_a, stack_b);
	rr(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	ra(stack_a);
	print_stack(stack_a, stack_b);
	rb(stack_b);
	print_stack(stack_a, stack_b);
	rrr(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	*/
	return (0);
}
