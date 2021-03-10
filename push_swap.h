#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h> // delete include

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

// ft_stack
void				ft_stackadd_back(t_stack **st, t_stack *new);
void				ft_stackadd_front(t_stack **st, t_stack *new);
void				ft_stackclear(t_stack **st);
t_stack				*ft_stacknew(int n);
int					ft_stacksize(t_stack *st);

// utils
long long			ft_atol(const char *str);
char				*ft_strdup_size(const char *s1, int left, int right);
void				ft_init_ary(t_array *ary, t_stack *st);
void				ft_wrong_cmd_exit(t_array *a, t_array *b, char *line);

// ft_swap
void				ft_stackswap(t_stack *st, t_stack *st2);
void				ft_aryswap(t_array *ary1, t_array *ary2);

// ft_push
void				ft_stackpush(t_stack **get, t_stack **set);
void				ft_arypush(t_array *get, t_array *set);

// ft_rotate
void				ft_stackrotate(t_stack **st, t_stack **st2);
void				ft_stackrotate_r(t_stack **st, t_stack **st2);
void				ft_aryrotate(t_array *ary1, t_array *ary2);
void				ft_aryrotate_r(t_array *ary1, t_array *ary2);

// ft_set_stack
void				ft_set_stack(char **argv, t_stack **a);

// get_next_line
int					get_next_line(int fd, char **line);

#endif
