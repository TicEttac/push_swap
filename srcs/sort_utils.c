#include "push_swap.h"

t_list	*copy(t_list *a)
{
	t_list	*ret;
	t_list	*tmp;

	ret = build_link(a->content);
	tmp = ret;
	while (a->next)
	{
		a = a->next;
		tmp->next = build_link(a->content);
		tmp = tmp->next;
	}
	return (ret);
}

int	revert_step(t_inst **inst, t_list **a)
{
	t_inst	*tmp;
	t_inst	*tmp2;

	tmp = *inst;
	if (tmp && tmp->next)
	{
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		revert_list(a, tmp->content);
		free(tmp);
		tmp2->next = NULL;
		return (0);
	}
	if (tmp)
		revert_list(a, tmp->content);
	free(tmp);
	*inst = NULL;
	return (0);
}

void	revert_list(t_list **a, int order)
{
	if (order == SA)
		sa(a);
	if (order == RA)
		rra(a);
	if (order == RRA)
		ra(a);
}