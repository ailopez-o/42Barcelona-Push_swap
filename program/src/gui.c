/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:36:12 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/08/03 21:36:15 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../lib/miniliblx/minilibx_macos/mlx.h"
#include "../lib/libft/libft.h"
#include "../inc/print.h"
#include "../inc/lst_utils.h"
#include "../inc/instructions.h"
#include "../inc/draw.h"
#include "../inc/sort.h"
#include "../inc/gui_utils.h"
#include <math.h>

int draw_bar(t_meta *meta, t_bar bar)
{
	int	i;

	i = 0;
	while (i < bar.width)
	{
		draw_line(meta, bar.start, bar.end);
		bar.start.axis[Y]++;;
		bar.end.axis[Y]++;
		i++;
	}
	return (1);
}


void get_line_stack_a(t_bar *bar, int value, int max, int neg)
{
	float len;
	
	len = bar_len(value, max, neg);
	if (value >= 0)
	{
		if (neg)
		{
			bar->start.axis[X] = WINX / 4;
			bar->end.axis[X] = WINX / 4 + len;
		}
		else
		{
			bar->start.axis[X] = WINX / 2 - len;
			bar->end.axis[X] = WINX / 2;
		}
	}
	else
	{
			bar->start.axis[X] = WINX / 4 - len;
			bar->end.axis[X] = WINX / 4;
	}
}

void	get_line_stack_b(t_bar *bar, int value, int max, int neg)
{
	float len;

	len = bar_len(value, max, neg);
	if (value >= 0)
	{
		if (neg)
		{
			bar->start.axis[X] = 3 * (WINX / 4);
			bar->end.axis[X] = 3 * (WINX / 4) + len;
		}
		else
		{
			bar->start.axis[X] = WINX / 2;
			bar->end.axis[X] = WINX / 2 + len;
		}
	}
	else
	{
			bar->start.axis[X] = 3 * (WINX / 4) - len;
			bar->end.axis[X] = 3 * (WINX / 4);
	}
}

int	draw_stack(t_meta *meta, int stack_side)
{
	int i;
	t_bar	bar;
	t_stack *stack;

	stack = meta->stack_a;
	if (stack_side == STACKB)
		stack = meta->stack_b;
	if (!stack)
		return (0);
	bar.width = (WINY) / meta->stack_size;
	//printf("values [%d] - Width[%d]\n", meta->stack_size, bar.width);
	i = 0;
	while (stack)
	{
		load_colors_stacks(&bar, stack_side);
		if (stack_side == STACKA)
			get_line_stack_a(&bar, stack->num, meta->abs, meta->neg);
		if (stack_side == STACKB)
			get_line_stack_b(&bar, stack->num, meta->abs, meta->neg);
		bar.start.axis[Y] = bar.width * i;
		bar.end.axis[Y] = bar.width * i;		
		draw_bar(meta, bar);
		stack = stack->next;
		i++;
	}
	return (1);
}

int draw_push_swap(t_meta *meta)
{
	char	*str;
	char	*strnumops;
	char	*print;

	generate_background(meta, CARBON);
	//draw_half(meta);
    draw_stack(meta, STACKA);
	draw_stack(meta, STACKB);
    mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, \
	meta->bitmap.img, 0, 0);
	str = ft_strdup("operations: ");
	strnumops = ft_itoa(meta->numops);
	print = ft_strjoin(str, strnumops);
	mlx_string_put(meta->vars.mlx, meta->vars.win, WINX - 200, WINY - 30, VERDE, print);
	free (str);
	free (strnumops);
	free (print);
	mlx_do_sync(meta->vars.mlx);
    return (1);
}



