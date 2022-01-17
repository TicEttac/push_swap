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
	if (order == SB)
		if (apply(a, inst, SB, 1) && (bt_revert(a, inst, depth + 1, RB)
				|| bt_revert(a, inst, depth + 1, RRB)))
			return (1);
	if (order == RB)
		if (apply(a, inst, RB, 1) && (bt_revert(a, inst, depth + 1, SB)
				|| bt_revert(a, inst, depth + 1, RB)))
			return (1);
	if (order == RRB)
		if (apply(a, inst, RRB, 1) && (bt_revert(a, inst, depth + 1, SB)
				|| bt_revert(a, inst, depth + 1, RRB)))
			return (1);
	return (revert_step(inst, a));
}

t_inst	*launch_revert(t_list **a)
{
	t_inst	*inst;

	inst = NULL;
	if (bt_revert(a, &inst, 0, SB))
		return (inst);
	free_list((t_list *)inst);
	inst = NULL;
	if (bt_revert(a, &inst, 0, RB))
		return (inst);
	free_list((t_list *)inst);
	inst = NULL;
	if (bt_revert(a, &inst, 0, RRB))
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

int     find_median(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;
	int	more;
	int	less;

	tmp = *a;
	while (tmp)
	{
		more = 0;
		less = 0;
		tmp2 = *a;
		while (tmp2)
		{
			more += (int)(tmp2->content > tmp->content);
			less += (int)(tmp2->content < tmp->content);
			tmp2 = tmp2->next;
		}
		if (less - more <= 1 && less - more >= -1)
			break ;
		tmp = tmp->next;
	}
	return (tmp->content);
	
}

void	push_to_b(t_list **a, t_list **b, int i)
{
	int		j;
	int		lenght;

	j = 0;
	lenght = list_size(*a);
	if (i < lenght - i)
		while (j < i)
		{
			rotate_a(a);
			j++;
		}
	else
		while (j < i)
		{
			revrotate_a(a);
			j++;
		}
	push_b(a, b);
}

t_list	*build_b(t_list **a)
{
	t_list		*ret;
	t_list		*tmp;
	int		i;
	int		median;

	ret = NULL;
	median = find_median(a);
	while (1)
	{
		i = 0;
		tmp = *a;
		while (tmp && tmp->content > median)
		{
			tmp = tmp->next;
			i++;
		}
		if (!tmp)
			break ;
		else
			push_to_b(a, &ret, i);
	}
	return (ret);
}

void    middle_sort(t_list **a)
{
	t_list		*b;

	b = NULL;
	b = build_b(a);
	revert_small(&b);
	small_sort(a);
	while (b)
	{
		push_b(a, &b);
	}
	free_list(b);
}
