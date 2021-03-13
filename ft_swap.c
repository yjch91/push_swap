#include "push_swap.h"

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
