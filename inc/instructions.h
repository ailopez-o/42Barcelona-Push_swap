#ifndef INSTRUCCTIONS_H
# define INSTRUCCTIONS_H

# include "../inc/defines.h"

int sa(t_stack *stack);
int sb(t_stack *stack);
int ss(t_stack *stack_a, t_stack *stack_b);
int pa(t_stack **stack_a, t_stack **stack_b);
int pb(t_stack **stack_a, t_stack **stack_b);
int	ra(t_stack *stack);
int	rb(t_stack *stack);
int	rr(t_stack *stack_a, t_stack *stack_b);
int	rra(t_stack *stack);
int	rrb(t_stack *stack);
int	rrr(t_stack *stack_a, t_stack *stack_b);
#endif