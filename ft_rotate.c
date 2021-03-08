#include "push_swap.h"

void	ft_stackrotate(t_stack **st, t_stack **st2)
{
	t_stack	*temp;

	if (ft_stacksize(*st) > 1)
	{
		ft_stackadd_back(st, ft_stacknew((*st)->num));
		temp = *st;
		*st = (*st)->next;
		free(temp);
	}
	if (st2 != 0 && ft_stacksize(*st2) > 1)
	{
		ft_stackadd_back(st2, ft_stacknew((*st2)->num));
		temp = *st2;
		*st2 = (*st2)->next;
		free(temp);
	}
}

void	ft_stackrm_last(t_stack **st)
{
	t_stack *last;
	t_stack	*temp;

	last = *st;
	while (last != 0)
	{
		if (last->next == 0)
			break ;
		if (last->next->next == 0)
			temp = last;
		last = last->next;
	}
	temp->next = 0;
	ft_stackadd_front(st, ft_stacknew(last->num));
	free(last);
}

void	ft_stackrotate_r(t_stack **st, t_stack **st2)
{
	if (ft_stacksize(*st) > 1)
		ft_stackrm_last(st);
	if (st2 != 0 && ft_stacksize(*st2) > 1)
		ft_stackrm_last(st2);
}
