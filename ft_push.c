#include "push_swap.h"

void	ft_stackpush(t_stack **get, t_stack **set)
{
	t_stack	*temp;

	if (ft_stacksize(*get) > 0)
	{
		ft_stackadd_front(set, ft_stacknew((*get)->num));
		temp = *get;
		*get = (*get)->next;
		free(temp);
	}
}

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

t_array	*ft_arypush_get(t_array *get, int size)
{
	t_array	*result;
	int		i;

	result = ft_arycopy(get, size);
	if (get->last > -1)
	{
		i = 0;
		while (i < get->last)
		{
			result->ary[i] = get->ary[i + 1];
			i++;
		}
		result->last--;
	}
	return (result);
}

t_array	*ft_arypush_set(t_array *get, t_array *set, int size)
{
	t_array *result;
	int		i;

	result = ft_arycopy(set, size);
	if (get->last > -1)
	{
		i = set->last + 1;
		while (i > 0)
		{
			result->ary[i] = set->ary[i - 1];
			i--;
		}
		result->last++;
	}
	return (result);
}
