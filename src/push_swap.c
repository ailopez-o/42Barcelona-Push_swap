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
#include "../inc/listhandle.h"
#include "../inc/print.h"
#include <stddef.h>

void	ini_stack(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	free (stack);
	stack = NULL;
}


int main (int argv, char **argc)
{
    int i;
    t_stack	*stack_a;
    t_stack	*stack_b;
    t_stack	*new;

    if (argv < 2)
        return (0);
    i = 1;
	stack_a = NULL;
	stack_b = NULL;
	new = NULL;
	ini_stack(stack_b);
	stack_lstadd_back(&stack_b, new);
    while (i < argv)
    {
		new = ft_stacklstnew(ft_atoi(argc[i]));
        stack_lstadd_back(&stack_a, new);
        i++;
    }
    print_stack(stack_a, stack_b);
    return (0);
}
