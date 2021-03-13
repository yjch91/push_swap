#include "push_swap.h"

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
