/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:05:37 by jayun             #+#    #+#             */
/*   Updated: 2021/03/14 21:57:58 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_info	*ft_init_info(t_array *a, int n)
{
	t_info	*result;

	result = (t_info *)malloc(sizeof(t_info));
	result->group = 1;
	if (n <= 50)
		result->set = 2;
	else if (n <= 200)
		result->set = 3;
	else
		result->set = n / 60;
	result->n = n;
	result->back = 0;
	result->count = 0;
	result->x = 0;
	result->c = ft_arycopy(a, n);
	bubble_sort(result->c, n);
	return (result);
}

static void		sol3(t_array *a, t_array *b, t_info *info, int push_num)
{
	int	num;

	push_num = 0;
	num = info->c->ary[info->count + 2];
	while (push_num < 3)
	{
		if (b->ary[0] <= num)
		{
			ft_apply_cmd(a, b, "pa");
			push_num++;
		}
		else
			ft_apply_cmd(a, b, "rb");
		if (a->ary[0] == info->c->ary[info->count])
			ft_apply_cmd(a, b, "ra");
	}
	if (a->ary[0] > a->ary[1])
		ft_apply_cmd(a, b, "sa");
	ft_apply_cmd(a, b, "ra");
	ft_apply_cmd(a, b, "ra");
	info->count += 3;
}

static void		sol2(t_array *a, t_array *b, t_info *info)
{
	int	num;

	num = info->c->ary[info->n * info->group / info->set - 1];
	info->back = 0;
	while (info->x < (info->n * info->group / info->set))
	{
		if (a->ary[0] <= num)
		{
			ft_apply_cmd(a, b, "pb");
			info->x++;
		}
		else
		{
			ft_apply_cmd(a, b, "ra");
			info->back++;
		}
	}
	if (info->group > 1 && info->group < info->set)
		while (info->back--)
			ft_apply_cmd(a, b, "rra");
}

void			sol(t_array *a, t_array *b, int n)
{
	t_info	*info;

	info = ft_init_info(a, n);
	while (info->group <= info->set)
	{
		sol2(a, b, info);
		while (b->last >= 2)
			sol3(a, b, info, 0);
		if (b->last == 1 && b->ary[0] > b->ary[1])
			ft_apply_cmd(a, b, "sb");
		while (b->last > -1)
		{
			ft_apply_cmd(a, b, "pa");
			ft_apply_cmd(a, b, "ra");
			info->count++;
		}
		info->group++;
	}
	free(info->c->ary);
	free(info->c);
	free(info);
}
