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

void	ft_print(t_array *a, t_array *b)
{
	int	i;

	write(1, "a : ", 4);
	i = 0;
	while (i <= a->last)
	{
		ft_putnbr_fd(a->ary[i], 1);
		write(1, " ", 1);
		i++;
	}
	i = 0;
	write(1, "<> b : ", 7);
	while (i <= b->last)
	{
		ft_putnbr_fd(b->ary[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}


void		solution_3b(t_array *a, t_array *b)
{
	int	x;
	int	y;
	int z;

	x = b->ary[0];
	y = b->ary[1];
	z = b->ary[2];
	if (x < y && y > z && x < z)
	{
		ft_apply_cmd(a, b, "sb");
		ft_apply_cmd(a, b, "rb");
	}
	else if (x > y && y < z && x < z)
		ft_apply_cmd(a, b, "sb");
	else if (x < y && y > z && x > z)
		ft_apply_cmd(a, b, "rrb");
	else if (x > y && y < z && x > z)
		ft_apply_cmd(a, b, "rb");
	else if (x > y && y > z)
	{
		ft_apply_cmd(a, b, "rb");
		ft_apply_cmd(a, b, "sb");
	}
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

void		solution(t_array *a, t_array *b, int n)
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
		{
			if (a->ary[0] <= c->ary[2])
			{
				ft_apply_cmd(a, b, "pb");
				i++;
			}
			else
				ft_apply_cmd(a, b, "ra");
		}
		n -= 3;
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

void		sol(t_array *a, t_array *b, int n)
{
	int		i;
	int		x;
	int		count;
	int		push_num;
	t_array	*c;
	int		group;
	int		back;
	int		num;
	int		set;

	c = ft_arycopy(a, n);
	bubble_sort(c, n);
	count = 0;
	group = 1;
	x = 0;
	set = n / (n / 10);
	if (set == 0)
		set = 1;
	while (group <= set)
	{
		num = c->ary[n * group / set - 1];
		back = 0;
		while (x < (n * group / set))
		{
			if (a->ary[0] <= num)
			{
				ft_apply_cmd(a, b, "pb");
				x++;
			}
			else
			{
				ft_apply_cmd(a, b, "ra");
				back++;
			}
		}
		if (group > 1 && group < set)
			while (back--)
				ft_apply_cmd(a, b, "rra");
		while (b->last >= 2)
		{
			push_num = 0;
			while (push_num++ < 3)
			{
				num = c->ary[count++];
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
			if (a->last == 2)
				solution_3a(a, b);
			else
				solution_3a2(a, b);
			i = 3;
			while (i-- && a->last > 2)
				ft_apply_cmd(a, b, "ra");
		}
		if (b->last == 1 && b->ary[0] > b->ary[1])
			ft_apply_cmd(a, b, "sb");
		while (b->last > -1)
		{
			ft_apply_cmd(a, b, "pa");
			ft_apply_cmd(a, b, "ra");
			count++;
		}
		group++;
	}
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
			solution(&a, &b, n);
		else
			sol(&a, &b, n);
	}
	free(a.ary);
	free(b.ary);
	return (0);
}
