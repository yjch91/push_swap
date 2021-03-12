#include "push_swap.h"

static int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_duplicate_check(t_stack *a, int n)
{
	t_stack	*temp;

	temp = a;
	while (temp != 0)
	{
		if (temp->num == n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	ft_set_stack_exit(t_stack *a)
{
	write(2, "Error\n", 6);
	ft_stackclear(&a);
	exit(0);
}

void		ft_set_stack(char **argv, t_stack **a)
{
	int			i;
	int			len;
	int			n;

	i = 0;
	while (argv[++i] != 0)
	{
		len = ft_strlen(argv[i]);
		if (len == 1 && (argv[i][0] == '-' || argv[i][0] == '+'))
			ft_set_stack_exit(*a);
		if (len > 11 || ft_isdigit_str(argv[i]) == 0)
			ft_set_stack_exit(*a);
		n = ft_atol(argv[i]);
		if (n < -2147483648 || n > 2147483647 || ft_duplicate_check(*a, n) == 0)
			ft_set_stack_exit(*a);
		ft_stackadd_back(a, ft_stacknew(n));
	}
}
