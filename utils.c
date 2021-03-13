/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:06:00 by jayun             #+#    #+#             */
/*   Updated: 2021/03/14 02:06:01 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_init_ary(t_array *ary, t_stack *st)
{
	int i;

	i = 0;
	while (st != 0)
	{
		ary->ary[i++] = st->num;
		st = st->next;
	}
	ary->last = i - 1;
}

t_array		*ft_arycopy(t_array *ary, int size)
{
	t_array *result;
	int		i;

	result = (t_array *)malloc(sizeof(t_array));
	result->ary = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i <= ary->last)
	{
		result->ary[i] = ary->ary[i];
		i++;
	}
	result->last = ary->last;
	return (result);
}

void		bubble_sort(t_array *c, int n)
{
	int	i;
	int	j;
	int temp;

	i = n - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (c->ary[j] > c->ary[j + 1])
			{
				temp = c->ary[j];
				c->ary[j] = c->ary[j + 1];
				c->ary[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
}
