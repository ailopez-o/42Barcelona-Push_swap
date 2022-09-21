/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:41:08 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/08/03 21:41:10 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LST_UTILS_H
# define LST_UTILS_H

t_stack	*stack_lstnew(int num);
t_stack	*stack_lstlast(t_stack *lst);
void	stack_lstadd_back(t_stack **lst, t_stack *new);
void	stack_lstadd_front(t_stack **lst, t_stack *new);
int		stack_lstsize(t_stack *lst);
void	stack_lstfree(t_stack **lst);
int		stack_is_sorted(t_stack *first);
void	index_list(t_stack *stack);

#endif
