/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:39:30 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/08/03 21:39:32 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		key_press(int key, void *param);
int		terminate_program(void *param);
int		gui(t_meta *meta, char *op);
float	bar_len(int value, int max, int neg);
void	load_colors_stacks(t_bar *bar, int stack);
