#include "push_swap.h"

void	ft_msg_exit(t_stack *a, t_stack *b, char *line)
{
	write(2, "Error\n", 6);
	ft_stackclear(&a);
	if (b != 0)
		ft_stackclear(&b);
	if (line != 0)
		free(line);
	exit(0);
}

void	ft_apply_cmd(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0 && ft_strlen(line) == 2)
		ft_stackswap(*a, 0);
	else if (ft_strncmp(line, "sb", 2) == 0 && ft_strlen(line) == 2)
		ft_stackswap(*b, 0);
	else if (ft_strncmp(line, "ss", 2) == 0 && ft_strlen(line) == 2)
		ft_stackswap(*a, *b);
	else if (ft_strncmp(line, "pa", 2) == 0 && ft_strlen(line) == 2)
		ft_stackpush(b, a);
	else if (ft_strncmp(line, "pb", 2) == 0 && ft_strlen(line) == 2)
		ft_stackpush(a, b);
	else if (ft_strncmp(line, "ra", 2) == 0 && ft_strlen(line) == 2)
		ft_stackrotate(a, 0);
	else if (ft_strncmp(line, "rb", 2) == 0 && ft_strlen(line) == 2)
		ft_stackrotate(b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0 && ft_strlen(line) == 2)
		ft_stackrotate(a, b);
	else if (ft_strncmp(line, "rra", 3) == 0 && ft_strlen(line) == 3)
		ft_stackrotate_r(a, 0);
	else if (ft_strncmp(line, "rrb", 3) == 0 && ft_strlen(line) == 3)
		ft_stackrotate_r(b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0 && ft_strlen(line) == 3)
		ft_stackrotate_r(a, b);
	else
		ft_msg_exit(*a, *b, line);
}

int		ft_sort_check(t_stack *a, t_stack *b)
{
	int		flag;
	int		n;
	t_stack	*c;

	c = a->next;
	n = a->num;
	flag = 1;
	if (ft_stacksize(b) != 0)
		flag = 0;
	while (c != 0 && flag == 1)
	{
		if (n > c->num)
			flag = 0;
		n = c->num;
		c = c->next;
	}
	return (flag);
}

int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = 0;
	b = 0;
	if (argc == 1)
		return (0);
	ft_set_stack(argv, &a);
	while (ft_sort_check(a, b) == 0)
	{
	//	ft_apply_cmd(&a, &b, "ra");
	//	ft_putstr_fd("ra", 1);
	//	write(1, "\n", 1);
	}
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}
