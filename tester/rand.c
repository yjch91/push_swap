/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:01:39 by jayun             #+#    #+#             */
/*   Updated: 2021/03/14 02:03:33 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../libft/libft.h"

int	ary_check(int *ary, int n, int num)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (ary[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	*ary;
	int	num;
	int	n;
	int	i;

	if (argc == 1)
		return (0);
	n = ft_atoi(argv[1]);
	srand(time(NULL));
	ary = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		num = rand() % (n + 1);
		while (ary_check(ary, i, num) == 0)
			num = rand() % (n + 1);
		ary[i] = num;
		i++;
	}
	i = -1;
	while (++i < n)
		printf("%d ", ary[i]);
	return (0);
}
