#include "push_swap.h"

static void	sol_3b_r(t_array *a, t_array *b)
{
	int	x;
	int	y;
	int z;

	x = b->ary[0];
	y = b->ary[1];
	z = b->ary[2];
	if (x < y && y < z)
	{
		ft_apply_cmd(a, b, "sb");
		ft_apply_cmd(a, b, "rrb");
	}
	else if (x < y && y > z && x < z)
		ft_apply_cmd(a, b, "rb");
	else if (x > y && y < z && x < z)
		ft_apply_cmd(a, b, "rrb");
	else if (x < y && y > z && x > z)
		ft_apply_cmd(a, b, "sb");
	else if (x > y && y < z && x > z)
	{
		ft_apply_cmd(a, b, "rrb");
		ft_apply_cmd(a, b, "sb");
	}
}

static void	sol_3a(t_array *a, t_array *b)
{
	int	x;
	int	y;
	int z;

	x = a->ary[0];
	y = a->ary[1];
	z = a->ary[2];
	if (x < y && y > z && x < z)
	{
		ft_apply_cmd(a, b, "sa");
		ft_apply_cmd(a, b, "ra");
	}
	else if (x > y && y < z && x < z)
		ft_apply_cmd(a, b, "sa");
	else if (x < y && y > z && x > z)
		ft_apply_cmd(a, b, "rra");
	else if (x > y && y < z && x > z)
		ft_apply_cmd(a, b, "ra");
	else if (x > y && y > z)
	{
		ft_apply_cmd(a, b, "ra");
		ft_apply_cmd(a, b, "sa");
	}
}

static void	sol3_5_2(t_array *a, t_array *b, int n)
{
	int	i;

	if (n == 2 && a->ary[0] > a->ary[1])
		ft_apply_cmd(a, b, "sa");
	while (b->last != -1)
	{
		sol_3b_r(a, b);
		i = 3;
		while (i--)
			ft_apply_cmd(a, b, "pa");
	}
}

void		sol3_5(t_array *a, t_array *b, int n)
{
	t_array	*c;
	int		i;

	if (n == 3)
		sol_3a(a, b);
	else
	{
		c = ft_arycopy(a, n);
		bubble_sort(c, n);
		i = 0;
		while (i < 3)
			if (a->ary[0] <= c->ary[2])
			{
				ft_apply_cmd(a, b, "pb");
				i++;
			}
			else
				ft_apply_cmd(a, b, "ra");
		sol3_5_2(a, b, n - 3);
	}
}
