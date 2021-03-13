#include "push_swap.h"

void	ft_stackswap(t_stack *st, t_stack *st2)
{
	t_stack	*a;
	t_stack *b;
	int		n;

	if (ft_stacksize(st) > 1)
	{
		a = st;
		b = st->next;
		n = a->num;
		a->num = b->num;
		b->num = n;
	}
	if (st2 != 0 && ft_stacksize(st2) > 1)
	{
		a = st2;
		b = st2->next;
		n = a->num;
		a->num = b->num;
		b->num = n;
	}
}

void	ft_aryswap(t_array *ary1, t_array *ary2)
{
	int	n;

	if (ary1->last > 0)
	{
		n = ary1->ary[0];
		ary1->ary[0] = ary1->ary[1];
		ary1->ary[1] = n;
	}
	if (ary2 != 0 && ary2->last > 0)
	{
		n = ary2->ary[0];
		ary2->ary[0] = ary2->ary[1];
		ary2->ary[1] = n;
	}
}

t_array	*ft_aryswap_rt(t_array *ary, int size)
{
	t_array	*result;

	result = ft_arycopy(ary, size);
	ft_aryswap(result, 0);
	return (result);
}
