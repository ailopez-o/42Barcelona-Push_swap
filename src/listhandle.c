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

t_stack	*ft_lstlast(t_stack *lst)
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
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}