#include "push_swap.h"

void	ft_arypush(t_array *get, t_array *set)
{
	int	i;

	if (get->last > -1)
	{
		i = set->last + 1;
		while (i > 0)
		{
			set->ary[i] = set->ary[i - 1];
			i--;
		}
		set->ary[0] = get->ary[0];
		i = 0;
		while (i < get->last)
		{
			get->ary[i] = get->ary[i + 1];
			i++;
		}
		get->last--;
		set->last++;
	}
}
