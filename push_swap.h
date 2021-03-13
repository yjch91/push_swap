/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:05:24 by jayun             #+#    #+#             */
/*   Updated: 2021/03/14 02:08:31 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_array
{
	int				*ary;
	int				last;
}					t_array;

typedef struct		s_info
{
	int				group;
	int				set;
	int				n;
	int				back;
	int				count;
	int				x;
	t_array			*c;
}					t_info;

void				ft_apply_cmd(t_array *a, t_array *b, char *line);

/*
** 	ft_stack
*/

void				ft_stackadd_back(t_stack **st, t_stack *new);
void				ft_stackclear(t_stack **st);
t_stack				*ft_stacknew(int n);
int					ft_stacksize(t_stack *st);

/*
**	utils
*/

long long			ft_atol(const char *str);
char				*ft_strdup_size(const char *s1, int left, int right);
void				ft_init_ary(t_array *ary, t_stack *st);
t_array				*ft_arycopy(t_array *ary, int size);
void				bubble_sort(t_array *c, int n);

/*
**	ft_swap
*/

void				ft_aryswap(t_array *ary1, t_array *ary2);

/*
**	ft_push
*/

void				ft_arypush(t_array *get, t_array *set);

/*
**	ft_rotate
*/

void				ft_aryrotate(t_array *ary1, t_array *ary2);
void				ft_aryrotate_r(t_array *ary1, t_array *ary2);

/*
**	ft_set_stack
*/

void				ft_set_stack(char **argv, t_stack **a);

/*
**	get_next_line
*/

int					get_next_line(int fd, char **line);

/*
**	sol
*/

void				sol(t_array *a, t_array *b, int n);

/*
**	sol_3a_back
*/

void				sol_3a_back(t_array *a, t_array *b);

/*
**	sol3_5
*/

void				sol3_5(t_array *a, t_array *b, int n);

#endif
