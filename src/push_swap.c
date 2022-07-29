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
#include "../lib/libft/libft.h"
#include "../inc/defines.h"
#include "../inc/lst_utils.h"
#include "../inc/print.h"
#include "../inc/instructions.h"
#include <stddef.h>

int	short_stack(t_stack *stack_a, t_stack **stack_b)
{
	t_stack	*new;

	while(stack_a)
	{
		new = ft_stacklstnew(stack_a->num);
        stack_lstadd_back(stack_b, new);
		stack_a = stack_a->next;
	}
	return (1);
}

int	fill_stack(t_stack **stack, char **values)
{
	int	i;
    t_stack	*new;

	i = 1;
    while (values[i])
    {
		new = ft_stacklstnew(ft_atoi(values[i]));
        stack_lstadd_back(stack, new);
        i++;
    }
	return (1);
}

int main (int argv, char **argc)
{
    t_stack	*stack_a;
    t_stack	*stack_b;

    if (argv < 2)
        return (0);
	stack_a = NULL;
	stack_b = NULL;
	fill_stack(&stack_a, argc);
	short_stack(stack_a, &stack_b);
    print_stack(stack_a, stack_b);
	execute(SA,stack_a,stack_b);
    print_stack(stack_a, stack_b);
	execute(SB,stack_a,stack_b);
    print_stack(stack_a, stack_b);
	execute(SS,stack_a,stack_b);
    print_stack(stack_a, stack_b);
	execute(RA,stack_a,stack_b);
    print_stack(stack_a, stack_b);
	execute(RB,stack_a,stack_b);
    print_stack(stack_a, stack_b);
	execute(RR,stack_a,stack_b);
    print_stack(stack_a, stack_b);
	execute(RRA,stack_a,stack_b);
    print_stack(stack_a, stack_b);
	execute(RRB,stack_a,stack_b);
    print_stack(stack_a, stack_b);
	execute(RRR,stack_a,stack_b);
    print_stack(stack_a, stack_b);	
    return (0);
}
