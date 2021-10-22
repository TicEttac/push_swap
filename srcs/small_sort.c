/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 02:23:36 by nisauvig          #+#    #+#             */
/*   Updated: 2021/10/22 17:29:23 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_inst(t_inst **inst, int order)
{
	t_inst	*tmp;

	if (!*inst)
	{
		printf("0\n");
		*inst = malloc(sizeof(t_inst));
		if (!inst)
			return (0);
		(*inst)->content = order;
		(*inst)->next = NULL;
		return (1);
	}
	printf("+1\n");
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
	if (order == SA)
		sa(a);
	if (order == RA)
		ra(a);
	if (order == RRA)
		rra(a);
	if (opt)
		return (add_inst(inst, order));
	return (0);
}

void	apply_inst(t_list **a, t_inst *inst)
{
	while (inst)
	{
		if (inst->content == SA)
			ft_putstr("sa\n");
		if (inst->content == RA)
			ft_putstr("ra\n");
		if (inst->content == RRA)
			ft_putstr("rra\n");
		apply(a, NULL, inst->content, 0);
		inst = inst->next;
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

void	revert_list(t_list **a, int order)
{
	if (order == SA)
		sa(a);
	if (order == RA)
		rra(a);
	if (order == RRA)
		ra(a);
}

int	revert_step(t_inst **inst, t_list **a)
{
	t_inst	*tmp;
	t_inst	*tmp2;

	tmp = *inst;
	printf("-1\n");
	if (tmp->next)
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
	revert_list(a, tmp->content);
	free(tmp);
	tmp = NULL;
	return (0);
}

int	bt_small(t_list **a, t_inst **inst, int depth, int order)
{
	if (check_list(a))
		return (1);
	if (depth == MAX_DEPTH)
		return (revert_step(inst, a));
	if (order == SA)
		if (apply(a, inst, SA, 1) && (bt_small(a, inst, depth + 1, RA)
				|| bt_small(a, inst, depth + 1, RRA)))
			return (1);
	if (order == RA)
		if (apply(a, inst, RA, 1) && (bt_small(a, inst, depth + 1, SA)
				|| bt_small(a, inst, depth + 1, RA)))
			return (1);
	if (order == RRA)
		if (apply(a, inst, RRA, 1) && (bt_small(a, inst, depth + 1, SA)
				|| bt_small(a, inst, depth + 1, RRA)))
			return (1);
	return (revert_step(inst, a));
}

t_inst	*launch_small(t_list **a)
{
	t_inst	*inst;

	inst = NULL;
	if (bt_small(a, &inst, 0, SA))
		return (inst);
	free_list((t_list *)inst);
	inst = NULL;
	if (bt_small(a, &inst, 0, RA))
		return (inst);
	free_list((t_list *)inst);
	inst = NULL;
	if (bt_small(a, &inst, 0, RRA))
		return(inst);
	return (NULL);
}

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

int	small_sort(t_list **a)
{
	t_inst	*inst;
	t_list	*cp_a;

	cp_a = copy(*a);
	inst = launch_small(&cp_a);
	if (!inst)
		return (0);
	apply_inst(a, inst);
	print_list(cp_a, 'C');
	free_list(cp_a);
	free_list((t_list *)inst);
	return (1);
}
