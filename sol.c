#include "push_swap.h"

t_info		*ft_init_info(t_array *a, int n)
{
	t_info	*result;

	result = (t_info *)malloc(sizeof(t_info));
	result->group = 1;
	if (n <= 10)
		result->set = 1;
	else if (n <= 50)
		result->set = 2;
	else if (n <= 100)
		result->set = 3;
	else
		result->set = n / (n / 10);
	if (result->set == 0)
		result->set = 1;
	result->n = n;
	result->back = 0;
	result->count = 0;
	result->x = 0;
	result->c = ft_arycopy(a, n);
	bubble_sort(result->c, n);
	return (result);
}

void		sol3(t_array *a, t_array *b, t_info *info, int push_num)
{
	int	num;
	int	i;

	push_num = 0;
	while (push_num++ < 3)
	{
		num = info->c->ary[info->count++];
		i = 0;
		while (b->ary[i] != num)
			i++;
		if (i <= (b->last + 1) / 2)
			while (i--)
				ft_apply_cmd(a, b, "rb");
		else
		{
			i = b->last + 1 - i;
			while (i--)
				ft_apply_cmd(a, b, "rrb");
		}
		ft_apply_cmd(a, b, "pa");
	}
	sol_3a_back(a, b);
	i = 3;
	while (i--)
		ft_apply_cmd(a, b, "ra");
}

void		sol2(t_array *a, t_array *b, t_info *info)
{
	int	num;

	num = info->c->ary[info->n * info->group / info->set - 1];
	info->back = 0;
	while (info->x < (info->n * info->group / info->set))
	{
		if (a->ary[0] <= num)
		{
			ft_apply_cmd(a, b, "pb");
			info->x++;
		}
		else
		{
			ft_apply_cmd(a, b, "ra");
			info->back++;
		}
	}
	if (info->group > 1 && info->group < info->set)
		while (info->back--)
			ft_apply_cmd(a, b, "rra");
}

void		sol(t_array *a, t_array *b, int n)
{
	t_info	*info;

	info = ft_init_info(a, n);
	while (info->group <= info->set)
	{
		sol2(a, b, info);
		while (b->last >= 2)
			sol3(a, b, info, 0);
		if (b->last == 1 && b->ary[0] > b->ary[1])
			ft_apply_cmd(a, b, "sb");
		while (b->last > -1)
		{
			ft_apply_cmd(a, b, "pa");
			ft_apply_cmd(a, b, "ra");
			info->count++;
		}
		info->group++;
	}
	free(info->c->ary);
	free(info->c);
	free(info);
}
