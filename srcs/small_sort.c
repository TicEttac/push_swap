/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 02:23:36 by nisauvig          #+#    #+#             */
/*   Updated: 2021/10/29 19:20:19 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_inst(t_inst **inst, int order)
{
	t_inst	*tmp;

	if (!*inst)
	{
		*inst = malloc(sizeof(t_inst));
		if (!inst)
			return (0);
		(*inst)->content = order;
		(*inst)->next = NULL;
		return (1);
	}
	tmp = *inst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(t_inst));
	if (!tmp->next)
		return (0);
	tmp->next->content = order;
	tmp->next->next = NULL;
	return (1);
}

int	apply(t_list **a, t_inst **inst, int order, int opt)
{
	if (order == SA || order == SB)
		sa(a);
	if (order == RA || order == RB)
		ra(a);
	if (order == RRA || order == RRB)
		rra(a);
	if (opt)
		return (add_inst(inst, order));
	return (0);
}

void	apply_inst(t_inst **inst)
{
	static const t_tab	tab[] = {{"ra", RA}, {"rra", RRA}, {"sa", SA},
		{"rb", RB},{"rrb", RRB},{"sb", SB}};
	int			i;
    t_inst      *tmp;

    tmp = *inst;
	while (tmp)
	{
		i = 0;
		while (i < 6)
		{
			if (tmp->content == tab[i].tag)
			{
				ft_putstr(tab[i].name);
				write(1, "\n", 1);
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	check_list(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}


int	bt_small(t_list **a, t_inst **inst, int depth, int order)
{
    apply(a, inst, order, 1);
	if (check_list(a))
		return (1);
	if (depth == MAX_DEPTH)
		return (revert_step(inst, a));
	if (order == SA)
		if (bt_small(a, inst, depth + 1, RA)
				|| bt_small(a, inst, depth + 1, RRA))
			return (1);
	if (order == RA)
		if (bt_small(a, inst, depth + 1, SA)
				|| bt_small(a, inst, depth + 1, RA))
			return (1);
	if (order == RRA)
		if (bt_small(a, inst, depth + 1, SA)
				|| bt_small(a, inst, depth + 1, RRA))
			return (1);
	return (revert_step(inst, a));
}

t_inst	*launch_small(t_list **a)
{
	t_inst	*inst;

	inst = NULL;
	if (bt_small(a, &inst, 0, SA))
		return (inst);
	else if (bt_small(a, &inst, 0, RA))
		return (inst);
	else if (bt_small(a, &inst, 0, RRA))
		return (inst);
	free_list((t_list *)inst);
	inst = NULL;
	return (NULL);
}

int	small_sort(t_list **a)
{
	t_inst	*inst;

	inst = launch_small(a);
	if (!inst)
		return (0);
	apply_inst(&inst);
	free_list((t_list *)inst);
	return (1);
}
