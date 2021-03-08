#include "push_swap.h"

void	ft_stackpush(t_stack **get, t_stack **set)
{
	t_stack	*temp;

	if (ft_stacksize(*get) > 0)
	{
		ft_stackadd_front(set, ft_stacknew((*get)->num));
		temp = *get;
		*get = (*get)->next;
		free(temp);
	}
}
