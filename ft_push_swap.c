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

void	ft_apply_oper(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0 && ft_strlen(line) == 2)
		ft_stackswap(*a, 0);
	else if (ft_strncmp(line, "sb", 2) == 0 && ft_strlen(line) == 2)
		ft_stackswap(*b, 0);
	else if (ft_strncmp(line, "ss", 2) == 0 && ft_strlen(line) == 2)
		ft_stackswap(*a, *b);
	else if (ft_strncmp(line, "pa", 2) == 0 && ft_strlen(line) == 2)
		ft_stackpush(a, b);
	else if (ft_strncmp(line, "pb", 2) == 0 && ft_strlen(line) == 2)
		ft_stackpush(b, a);
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

int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = 0;
	b = 0;
	if (argc == 1)
		return (0);
	ft_set_stack(argv, &a);
	ft_apply_oper(&a, &b, "sa");
	write(1, "sa\n", 3);
	ft_apply_oper(&a, &b, "rra");
	write(1, "rra\n", 4);
	return (0);
}
