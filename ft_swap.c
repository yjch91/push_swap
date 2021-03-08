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
