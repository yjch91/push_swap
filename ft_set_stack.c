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

static void	ft_set_stack_exit(t_stack *a, char **split)
{
	int	i;

	write(2, "Error\n", 6);
	ft_stackclear(&a);
	i = -1;
	while (split[++i] != 0)
		free(split[i]);
	free(split);
	exit(0);
}

static void	ft_set_stack2(t_stack **a, char **split, int j)
{
	int	len;
	int	n;

	len = ft_strlen(split[j]);
	if (len == 1 && (split[j][0] == '-' || split[j][0] == '+'))
		ft_set_stack_exit(*a, split);
	if (len > 11 || ft_isdigit_str(split[j]) == 0)
		ft_set_stack_exit(*a, split);
	n = ft_atol(split[j]);
	if (n < -2147483648 || n > 2147483647 || ft_duplicate_check(*a, n) == 0)
		ft_set_stack_exit(*a, split);
	ft_stackadd_back(a, ft_stacknew(n));
}

void		ft_set_stack(char **argv, t_stack **a)
{
	int			i;
	int			j;
	char		**split;

	i = 0;
	while (argv[++i] != 0)
	{
		split = ft_split(argv[i], 32);
		j = -1;
		while (split[++j] != 0)
			ft_set_stack2(a, split, j);
		j = -1;
		while (split[++j] != 0)
			free(split[j]);
		free(split);
	}
}
