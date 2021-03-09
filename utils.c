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
		if (minus == 1 && (result > 922337203685477580 ||
					(result == 922337203685477580 && str[i] > '7')))
			return (-1);
		else if (minus == -1 && (result > 922337203685477580 ||
					(result == 922337203685477580 && str[i] > '8')))
			return (0);
		result = result * 10 + str[i++] - '0';
	}
	return (result * minus);
}

char		*ft_strdup_size(const char *s1, int left, int right)
{
	int		i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (right - left + 1));
	if (temp == 0)
		return (0);
	temp[right - left] = '\0';
	i = 0;
	while (i < (right - left))
	{
		temp[i] = s1[left + i];
		i++;
	}
	return (temp);
}
