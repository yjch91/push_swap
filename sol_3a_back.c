/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_3a_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:05:53 by jayun             #+#    #+#             */
/*   Updated: 2021/03/14 02:05:54 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sol_3a_back1(t_array *a, t_array *b)
{
	ft_apply_cmd(a, b, "ra");
	ft_apply_cmd(a, b, "sa");
	ft_apply_cmd(a, b, "pb");
	ft_apply_cmd(a, b, "rra");
	ft_apply_cmd(a, b, "pa");
}

static void	sol_3a_back2(t_array *a, t_array *b)
{
	ft_apply_cmd(a, b, "sa");
	ft_apply_cmd(a, b, "ra");
	ft_apply_cmd(a, b, "sa");
	ft_apply_cmd(a, b, "rra");
}

static void	sol_3a_back3(t_array *a, t_array *b)
{
	ft_apply_cmd(a, b, "sa");
	ft_apply_cmd(a, b, "ra");
	ft_apply_cmd(a, b, "sa");
	ft_apply_cmd(a, b, "rra");
	ft_apply_cmd(a, b, "sa");
}

void		sol_3a_back(t_array *a, t_array *b)
{
	int	x;
	int	y;
	int z;

	x = a->ary[0];
	y = a->ary[1];
	z = a->ary[2];
	if (x < y && y > z && x < z)
	{
		ft_apply_cmd(a, b, "ra");
		ft_apply_cmd(a, b, "sa");
		ft_apply_cmd(a, b, "rra");
	}
	else if (x > y && y < z && x < z)
		ft_apply_cmd(a, b, "sa");
	else if (x < y && y > z && x > z)
		sol_3a_back1(a, b);
	else if (x > y && y < z && x > z)
		sol_3a_back2(a, b);
	else if (x > y && y > z)
		sol_3a_back3(a, b);
}
