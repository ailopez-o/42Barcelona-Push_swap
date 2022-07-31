#include "../inc/defines.h"
#include "../lib/miniliblx/minilibx_macos/mlx.h"
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

int draw_push_swap(t_meta *meta)
{
    mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, \
	meta->bitmap.img, 0, 0);
    return (1);
}

int	terminate_program(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
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

int draw_bar(t_meta *meta, t_point start, t_point end, int with)
{
	int	i;

	i = 0;
	while (i < with)
	{
		draw_line(meta, start, end);
		start.axis[Y]++;;
		end.axis[Y]++;
		i++;
	}
	return (1);
}

int	key_press(int key, void *param)
{
	t_meta	*meta;
	t_point	start;
	t_point end;	

	meta = (t_meta *)param;
    if (key == KEY_ESC)
		terminate_program(meta);
  	if (key == KEY_1)
	{
		start.axis[X] = 0;
		start.axis[Y] = WINY/2;
		start.color = AZUL;
		end.axis[X] = WINX/2;
		end.axis[Y] = WINY/2;
		end.color = ROJO;
		draw_bar(meta, start, end, 10);
		draw_push_swap(meta);
	}
 	if (key == KEY_2)
	{
		start.axis[X] = 0;
		start.axis[Y] = WINY/4;
		start.color = AZUL;
		end.axis[X] = WINX/4;
		end.axis[Y] = WINY/4;
		end.color = FUCSIA;
		draw_bar(meta, start, end, 20);
		draw_push_swap(meta);
	}	
	return (1);
}

