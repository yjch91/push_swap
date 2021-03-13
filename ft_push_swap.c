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

static void	search_sol(t_array *a, t_array *b, int n)
{
	if (n <= 5)
		sol3_5(a, b, n);
	else
		sol(a, b, n);
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
		search_sol(&a, &b, n);
	free(a.ary);
	free(b.ary);
	return (0);
}
