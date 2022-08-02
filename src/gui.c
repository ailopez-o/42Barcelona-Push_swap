#include "../inc/defines.h"
#include "../lib/miniliblx/minilibx_macos/mlx.h"
#include "../lib/libft/libft.h"
#include "../inc/algorithms.h"
#include "../inc/print.h"
#include "../inc/lst_utils.h"
#include "../inc/instructions.h"
#include <math.h>

int	get_color(t_meta *meta, int color)
{	
	if (meta->bitmap.bitxpixel != 32)
		color = mlx_get_color_value(meta->vars.mlx, color);
	return (color);
}

void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = (color) & 0xFF;
	}
	else
	{
		buffer[0] = (color) & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}

int	my_putpixel(t_meta *meta, t_point pixel)
{
	int	mypixel;

	if (pixel.axis[X] >= WINX || pixel.axis[Y] >= WINY || \
		pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return (-1);
	mypixel = ((int)pixel.axis[Y] * WINX * 4) + ((int)pixel.axis[X] * 4);
	if (meta->bitmap.bitxpixel != 32)
		pixel.color = mlx_get_color_value(meta->vars.mlx, pixel.color);
	set_color(&meta->bitmap.buffer[mypixel], \
		meta->bitmap.endian, pixel.color, 1);
	return (0);
}

int	generate_background(t_meta *meta, int backcolor)
{
	int	axis[2];
	int	pixel;

	backcolor = get_color(meta, backcolor);
	axis[X] = 0;
	axis[Y] = 0;
	while (axis[Y] < WINY)
	{
		while (axis[X] < WINX)
		{
			pixel = (axis[Y] * meta->bitmap.lines) + (axis[X] * 4);
			set_color(&meta->bitmap.buffer[pixel], \
						meta->bitmap.endian, backcolor, 1);
			axis[X]++;
		}
		axis[Y]++;
		axis[X] = 0;
	}
	return (1);
}

int	terminate_program(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
	stack_lstfree(&meta->stack_a);
	stack_lstfree(&meta->stack_b);		
	exit(0);
}

int	ft_round(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((endcolor >> 16) - \
					(startcolor >> 16)) / (double)len;
	increment[1] = (double)(((endcolor >> 8) & 0xFF) - \
					((startcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) \
					/ (double)len;
	new[0] = (startcolor >> 16) + ft_round(pix * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_round(pix * increment[1]);
	new[2] = (startcolor & 0xFF) + ft_round(pix * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}

int	draw_line(t_meta *meta, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;
	int		len;

	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	pixels = sqrt((delta.axis[X] * delta.axis[X]) + \
			(delta.axis[Y] * delta.axis[Y]));
	len = pixels;
	delta.axis[X] /= pixels;
	delta.axis[Y] /= pixels;
	pixel.axis[X] = start.axis[X];
	pixel.axis[Y] = start.axis[Y];
	while (pixels > 0)
	{
		pixel.color = gradient(start.color, end.color, len, len - pixels);
		my_putpixel(meta, pixel);
		pixel.axis[X] += delta.axis[X];
		pixel.axis[Y] += delta.axis[Y];
		pixels = pixels - 1;
	}
	return (1);
}

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

float	bar_len(int value, int max, int neg)
{
	float line_len;
	int	abs_value;

	abs_value = value;
	if (abs_value < 0)
		abs_value = -abs_value;
	line_len = WINX/2;
	if (neg)
		line_len = WINX/4;
	line_len = line_len * abs_value; 
	line_len = line_len / max;
	return (line_len);
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

void draw_half(t_meta *meta)
{
	t_bar bar;

	bar.start.axis[X] = WINX / 2;
	bar.start.axis[Y] = 0;
	bar.end.axis[X] = WINX / 2;
	bar.end.axis[Y] = WINY;
	bar.width = 3;
	bar.start.color = ROJO;
	bar.end.color = ROJO;
	draw_bar(meta, bar);
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

int gui(t_meta *meta, char *op)
{
	meta->numops++;
	if (meta->gui)
		draw_push_swap(meta);
	if (meta->print_ops)
		ft_putstr_fd(op, 1);
	if (meta->print_stack)
		print_stack	(meta->stack_a, meta->stack_b);
	return (1);
}

