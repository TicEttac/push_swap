#include "push_swap.h"

int	check_revert(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	bt_revert(t_list **a, t_inst **inst, int depth, int order)
{
	if (check_revert(a))
		return (1);
	if (depth == MAX_DEPTH)
		return (revert_step(inst, a));
	if (order == SA)
		if (apply(a, inst, SA, 1) && (bt_revert(a, inst, depth + 1, RA)
				|| bt_revert(a, inst, depth + 1, RRA)))
			return (1);
	if (order == RA)
		if (apply(a, inst, RA, 1) && (bt_revert(a, inst, depth + 1, SA)
				|| bt_revert(a, inst, depth + 1, RA)))
			return (1);
	if (order == RRA)
		if (apply(a, inst, RRA, 1) && (bt_revert(a, inst, depth + 1, SA)
				|| bt_revert(a, inst, depth + 1, RRA)))
			return (1);
	return (revert_step(inst, a));
}

t_inst	*launch_revert(t_list **a)
{
	t_inst	*inst;

	inst = NULL;
	if (bt_revert(a, &inst, 0, SA))
		return (inst);
	free_list((t_list *)inst);
	inst = NULL;
	if (bt_revert(a, &inst, 0, RA))
		return (inst);
	free_list((t_list *)inst);
	inst = NULL;
	if (bt_revert(a, &inst, 0, RRA))
		return(inst);
	return (NULL);
}

int	revert_small(t_list **a)
{
	t_inst	*inst;

	inst = launch_revert(a);
	if (!inst)
		return (0);
	apply_inst(a, inst);
	free_list((t_list *)inst);
	return (1);
}
/*
int     find_median(t_list **a)
{
	t_list	*tmp;
	int	lenght;

	lenght = 0;
	tmp = *a;
	while (tmp->next)
		lenght++;
	
}

void    middle_sort(t_list **a)
{
    t_list  *b;
    int     median;

    median = find_median(a);
}*/
