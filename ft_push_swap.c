#include "push_swap.h"

void		ft_apply_cmd(t_array *a, t_array *b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0 && ft_strlen(line) == 2)
		ft_aryswap(a, 0);
	else if (ft_strncmp(line, "sb", 2) == 0 && ft_strlen(line) == 2)
		ft_aryswap(b, 0);
	else if (ft_strncmp(line, "ss", 2) == 0 && ft_strlen(line) == 2)
		ft_aryswap(a, b);
	else if (ft_strncmp(line, "pa", 2) == 0 && ft_strlen(line) == 2)
		ft_arypush(b, a);
	else if (ft_strncmp(line, "pb", 2) == 0 && ft_strlen(line) == 2)
		ft_arypush(a, b);
	else if (ft_strncmp(line, "ra", 2) == 0 && ft_strlen(line) == 2)
		ft_aryrotate(a, 0);
	else if (ft_strncmp(line, "rb", 2) == 0 && ft_strlen(line) == 2)
		ft_aryrotate(b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0 && ft_strlen(line) == 2)
		ft_aryrotate(a, b);
	else if (ft_strncmp(line, "rra", 3) == 0 && ft_strlen(line) == 3)
		ft_aryrotate_r(a, 0);
	else if (ft_strncmp(line, "rrb", 3) == 0 && ft_strlen(line) == 3)
		ft_aryrotate_r(b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0 && ft_strlen(line) == 3)
		ft_aryrotate_r(a, b);
	write(1, line, ft_strlen(line));
	write(1, "\n", 1);
}

static int	ft_sort_check(t_array *a, t_array *b)
{
	int		flag;
	int		n;
	int		i;

	if (a->last == -1)
		return (0);
	flag = 1;
	n = a->ary[0];
	i = 1;
	if (b->last != -1)
		flag = 0;
	while (flag == 1 && i <= a->last)
	{
		if (n > a->ary[i])
			flag = 0;
		n = a->ary[i];
		i++;
	}
	return (flag);
}

void		bubble_sort(t_array *c, int n)
{
	int	i;
	int	j;
	int temp;

	i = n - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (c->ary[j] > c->ary[j + 1])
			{
				temp = c->ary[j];
				c->ary[j] = c->ary[j + 1];
				c->ary[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
}

void	solution_3b_r(t_array *a, t_array *b)
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

void		solution_3a(t_array *a, t_array *b)
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

void		sol3_5_2(t_array *a, t_array *b, int n)
{
	int	i;

	if (n == 2 && a->ary[0] > a->ary[1])
		ft_apply_cmd(a, b, "sa");
	while (b->last != -1)
	{
		solution_3b_r(a, b);
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
		solution_3a(a, b);
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

void		solution_3a2(t_array *a, t_array *b)
{
	int	x;
	int	y;
	int z;

	x = a->ary[0];
	y = a->ary[1];
	z = a->ary[2];
	if (x < y && y > z && x < z)
	{
		ft_apply_cmd(a, b, "ra");
		ft_apply_cmd(a, b, "sa");
		ft_apply_cmd(a, b, "rra");
	}
	else if (x > y && y < z && x < z)
		ft_apply_cmd(a, b, "sa");
	else if (x < y && y > z && x > z)
	{
		ft_apply_cmd(a, b, "ra");
		ft_apply_cmd(a, b, "sa");
		ft_apply_cmd(a, b, "pb");
		ft_apply_cmd(a, b, "rra");
		ft_apply_cmd(a, b, "pa");
	}
	else if (x > y && y < z && x > z)
	{
		ft_apply_cmd(a, b, "sa");
		ft_apply_cmd(a, b, "ra");
		ft_apply_cmd(a, b, "sa");
		ft_apply_cmd(a, b, "rra");
	}
	else if (x > y && y > z)
	{
		ft_apply_cmd(a, b, "sa");
		ft_apply_cmd(a, b, "ra");
		ft_apply_cmd(a, b, "sa");
		ft_apply_cmd(a, b, "rra");
		ft_apply_cmd(a, b, "sa");
	}
}

typedef struct	s_info
{
	int 		group;
	int			set;
	int			n;
	int			back;
	int			count;
	int			x;
	t_array		*c;
}				t_info;

t_info		*ft_init_info(t_array *a, int n)
{
	t_info	*result;

	result = (t_info *)malloc(sizeof(t_info));
	result->group = 1;
	if (n <= 100)
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
	solution_3a2(a, b);
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

int			main(int argc, char **argv)
{
	t_stack *s_a;
	t_stack *s_b;
	t_array	a;
	t_array b;
	int		n;

	s_a = 0;
	s_b = 0;
	if (argc == 1)
		return (0);
	ft_set_stack(argv, &s_a);
	n = ft_stacksize(s_a);
	a.ary = (int *)malloc(sizeof(int) * ft_stacksize(s_a));
	b.ary = (int *)malloc(sizeof(int) * ft_stacksize(s_a));
	ft_init_ary(&a, s_a);
	ft_init_ary(&b, s_b);
	ft_stackclear(&s_a);
	ft_stackclear(&s_b);
	if (ft_sort_check(&a, &b) == 0)
	{
		if (n <= 5)
			sol3_5(&a, &b, n);
		else
			sol(&a, &b, n);
	}
	free(a.ary);
	free(b.ary);
	return (0);
}
