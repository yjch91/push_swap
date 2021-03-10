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

void		ft_set_stack(char **argv, t_stack **a)
{
	int			i;
	int			j;
	int			len;
	long long	n;
	char		**split;

	i = 0;
	while (argv[++i] != 0)
	{
		split = ft_split(argv[i], 32);
		j = -1;
		while (split[++j] != 0)
		{
			len = ft_strlen(split[j]);
			if (len == 1 && (split[j][0] == '-' || split[j][0] == '+'))
				ft_msg_exit(*a, 0, 0);
			if (len > 11 || ft_isdigit_str(split[j]) == 0)
				ft_msg_exit(*a, 0, 0);
			n = ft_atol(split[j]);
			if (n < -2147483648 || n > 2147483647 || ft_duplicate_check(*a, n) == 0)
				ft_msg_exit(*a, 0, 0);
			ft_stackadd_back(a, ft_stacknew(n));
		}
	}
}
