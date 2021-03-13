/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:04:57 by jayun             #+#    #+#             */
/*   Updated: 2021/03/14 02:04:59 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **st, t_stack *new)
{
	t_stack *temp;

	temp = *st;
	while (temp)
	{
		if (temp->next == 0)
			break ;
		temp = temp->next;
	}
	if (temp)
		temp->next = new;
	else
		*st = new;
}

void	ft_stackclear(t_stack **st)
{
	t_stack	*temp;

	while (*st)
	{
		temp = (*st)->next;
		free(*st);
		*st = temp;
	}
}

t_stack	*ft_stacknew(int n)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == 0)
		return (0);
	temp->num = n;
	temp->next = 0;
	return (temp);
}

int		ft_stacksize(t_stack *st)
{
	t_stack	*temp;
	int		count;

	temp = st;
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
