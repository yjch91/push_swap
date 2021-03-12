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

void	solution_3a(t_array *a, t_array *b)
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
	int		max;
	int		push_num;
	int		i;
	int		count;
	int		back;
	int		pivot;

	if (n == 3)
		solution_3a(a, b);
	else
	{
		c = ft_arycopy(a, n);
		bubble_sort(c, n);
		pivot = c->ary[n / 2];
		count = 1;
		while (n >= 3)
		{
			max = c->ary[3 * count - 1];
			push_num = 0;
			back = 0;
			i = 0;
			while (push_num < 3)
			{
				if (a->ary[0] <= max)
				{
					ft_apply_cmd(a, b, "pb");
					push_num++;
				}
				else
				{
					ft_apply_cmd(a, b, "ra");
					back++;
				}
			}
			solution_3b(a, b);
			while (count != 1 && back--)
				ft_apply_cmd(a, b, "rra");
			i = 3;
			while (i--)
			{
				ft_apply_cmd(a, b, "pa");
				ft_apply_cmd(a, b, "ra");
			}
			n -= 3;
			count++;
		}
		if (n == 2 && a->ary[0] > a->ary[1])
			ft_apply_cmd(a, b, "sa");
		while (n--)
			ft_apply_cmd(a, b, "ra");
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
		solution(&a, &b, n);
	free(a.ary);
	free(b.ary);
	return (0);
}
