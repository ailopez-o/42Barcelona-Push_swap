/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:42:32 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/08/03 21:42:34 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SORT_H
# define SORT_H

void	sort(t_meta *meta);
void	sloted_sort(t_meta *meta);
void	pre_sort_slot(t_meta *meta, int num_slot, int slot_size);
void	smart_sort(t_meta *meta);

#endif