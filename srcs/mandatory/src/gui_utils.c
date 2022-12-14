/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:36:01 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/09/20 00:23:07 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../lib/miniliblx/minilibx_macos/mlx.h"
#include "../../../lib/libft/libft.h"
#include "../inc/defines.h"
#include "../inc/instructions.h"
#include "../inc/lst_utils.h"
#include "../inc/print.h"
#include "../inc/gui.h"
#include "../inc/sort.h"

int	terminate_program(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
	stack_lstfree(&meta->stack_a);
	stack_lstfree(&meta->stack_b);
	exit(0);
}

int	key_press(int key, void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	if (key == KEY_ESC)
		terminate_program(meta);
	if (key == KEY_S)
		sort(meta);
	if (key == KEY_1)
		sa(meta);
	if (key == KEY_2)
		sb(meta);
	if (key == KEY_3)
		ra(meta);
	if (key == KEY_4)
		rb(meta);
	if (key == KEY_5)
		rra(meta);
	if (key == KEY_6)
		rrb(meta);
	if (key == KEY_7)
		pa(meta);
	if (key == KEY_8)
		pb(meta);
	return (1);
}

void	load_colors_stacks(t_bar *bar, int stack)
{
	if (stack == STACKA)
	{
		bar->start.color = FUCSIA;
		bar->end.color = AZUL;
	}
	if (stack == STACKB)
	{
		bar->start.color = FLAMINGO;
		bar->end.color = VERDE;
	}	
}

float	bar_len(int value, int max, int neg)
{
	float	line_len;
	int		abs_value;

	abs_value = value;
	if (abs_value < 0)
		abs_value = -abs_value;
	line_len = WINX / 2;
	if (neg)
		line_len = WINX / 4;
	line_len = line_len * abs_value;
	line_len = line_len / max;
	return (line_len);
}

int	gui(t_meta *meta, char *op)
{
	meta->numops++;
	if (meta->gui)
		draw_push_swap(meta);
	if (meta->print_ops)
		ft_putstr_fd(op, 1);
	if (meta->print_stack)
		print_stack (meta->stack_a, meta->stack_b);
	return (1);
}
