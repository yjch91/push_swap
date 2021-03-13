#include "push_swap.h"

static void	ft_wrong_cmd_exit(t_array *a, t_array *b, char *line)
{
	write(2, "Error\n", 6);
	free(a->ary);
	free(b->ary);
	free(line);
	exit(0);
}

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
	else
		ft_wrong_cmd_exit(a, b, line);
}

static void	ft_read_cmd(t_array *a, t_array *b)
{
	char	*line;
	int		n;

	n = get_next_line(0, &line);
	while (n > 0)
	{
		ft_apply_cmd(a, b, line);
		free(line);
		n = get_next_line(0, &line);
	}
	if (n == 0)
		free(line);
	if (n == -1)
		ft_wrong_cmd_exit(a, b, 0);
}

static void	ft_sort_check(t_array *a, t_array *b)
{
	int		flag;
	int		n;
	int		i;

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
	if (flag == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int			main(int argc, char **argv)
{
	t_stack	*s_a;
	t_stack *s_b;
	t_array a;
	t_array b;

	s_a = 0;
	s_b = 0;
	if (argc == 1)
		return (0);
	ft_set_stack(argv, &s_a);
	a.ary = (int *)malloc(sizeof(int) * ft_stacksize(s_a));
	b.ary = (int *)malloc(sizeof(int) * ft_stacksize(s_a));
	ft_init_ary(&a, s_a);
	ft_init_ary(&b, s_b);
	ft_stackclear(&s_a);
	ft_stackclear(&s_b);
	ft_read_cmd(&a, &b);
	ft_sort_check(&a, &b);
	free(a.ary);
	free(b.ary);
	return (0);
}
