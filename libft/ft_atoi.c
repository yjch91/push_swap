/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:44:29 by jayun             #+#    #+#             */
/*   Updated: 2021/03/09 02:19:57 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
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
	return ((int)result * minus);
}
