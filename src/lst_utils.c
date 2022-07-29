#include "../inc/defines.h"

t_stack	*ft_stacklstnew(int num)
{
	t_stack	*stackitem;

	stackitem = malloc (sizeof(t_stack));
	if (stackitem == NULL)
		return (NULL);
	stackitem->num = num;
	stackitem->next = NULL;
    stackitem->pre = NULL;
	return (stackitem);
}

t_stack	*stack_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	t_stack *stack;

	stack = first;
	while (stack->next)
	{
		if (stack->num >= stack->next->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}