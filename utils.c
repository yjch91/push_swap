#include "push_swap.h"

long long	ft_atol(const char *str)
{
	int			i;
	int			minus;
	long long	result;

	i = 0;
	minus = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= 922337203685477580 && str[i] > '7' && minus == 1)
			return (-1);
		else if (result >= 922337203685477580 && str[i] > '8' && minus == -1)
			return (0);
		result = result * 10 + str[i++] - '0';
	}
	return (result * minus);
}