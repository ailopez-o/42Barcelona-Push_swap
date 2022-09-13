/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:41:50 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/08/03 21:41:52 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	get_index(t_stack *stack, int value);
int num_max(t_stack *stack);
t_stack *push_side(t_meta *meta, int side);
int are_values(t_stack *stack, int key_nbr);
void best_rr(t_meta *meta, int stack_size, int pos,int side);
