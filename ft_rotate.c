#include "push_swap.h"

void		ft_stackrotate(t_stack **st, t_stack **st2)
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

static void	ft_stackrotate_r2(t_stack **st)
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

void		ft_stackrotate_r(t_stack **st, t_stack **st2)
{
	if (ft_stacksize(*st) > 1)
		ft_stackrotate_r2(st);
	if (st2 != 0 && ft_stacksize(*st2) > 1)
		ft_stackrotate_r2(st2);
}

void		ft_aryrotate(t_array *ary1, t_array *ary2)
{
	int	n;
	int	i;

	if (ary1->last > 0)
	{
		n = ary1->ary[0];
		i = 0;
		while (i < ary1->last)
		{
			ary1->ary[i] = ary1->ary[i + 1];
			i++;
		}
		ary1->ary[i] = n;
	}
	if (ary2 != 0 && ary2->last > 0)
	{
		n = ary2->ary[0];
		i = 0;
		while (i < ary2->last)
		{
			ary2->ary[i] = ary2->ary[i + 1];
			i++;
		}
		ary2->ary[i] = n;
	}
}

void		ft_aryrotate_r(t_array *ary1, t_array *ary2)
{
	int	n;
	int	i;

	if (ary1->last > 0)
	{
		n = ary1->ary[ary1->last];
		i = ary1->last;
		while (i > 0)
		{
			ary1->ary[i] = ary1->ary[i - 1];
			i--;
		}
		ary1->ary[i] = n;
	}
	if (ary2 != 0 && ary2->last > 0)
	{
		n = ary2->ary[ary2->last];
		i = ary2->last;
		while (i > 0)
		{
			ary2->ary[i] = ary2->ary[i - 1];
			i--;
		}
		ary2->ary[i] = n;
	}
}

t_array		*ft_aryrotate_rt(t_array *ary, int size)
{
	t_array	*result;

	result = ft_arycopy(ary, size);
	ft_aryrotate(result, 0);
	return (result);
}

t_array		*ft_aryrotate_r_rt(t_array *ary, int size)
{
	t_array	*result;

	result = ft_arycopy(ary, size);
	ft_aryrotate_r(result, 0);
	return (result);
}
