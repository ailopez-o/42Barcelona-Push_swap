/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:04:59 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/31 18:05:02 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"

t_stack	*stack_lstnew(int num)
{
	t_stack	*new;

	new = malloc (sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->next = NULL;
	new->pre = NULL;
	return (new);
}

t_stack	*stack_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	stack_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	stack_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst)
	{
		last = stack_lstlast(*lst);
		last->next = new;
		new->pre = last;
	}
	else
		*lst = new;
}

int	stack_lstsize(t_stack *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 1;
	while (lst->next)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void	stack_lstfree(t_stack **lst)
{	
	t_stack	*elem;
	t_stack	*temp;

	elem = *lst;
	while (elem)
	{	
		temp = elem->next;
		free(elem);
		elem = temp;
	}
	*lst = NULL;
}

int	stack_is_sorted(t_stack *first)
{
	t_stack	*stack;

	if (!first)
		return (0);
	stack = first;
	while (stack->next)
	{
		if (stack->num >= stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
