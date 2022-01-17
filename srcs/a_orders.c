/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_orders.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:33:42 by nisauvig          #+#    #+#             */
/*   Updated: 2021/10/22 07:11:37 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*tmp;

	if ((*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		tmp->next = *a;
		*a = tmp;
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	(*b)->next = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

void	ra(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	(*a) = (*a)->next;
	tmp->next->next = NULL;
}

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *a;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	tmp2 = tmp->next;
	tmp->next = NULL;
	*a = tmp2;
}

void	rotate_a(t_list **a)
{
	printf("ra\n");
	ra(a);
}

void	revrotate_a(t_list **a)
{
	printf("rra\n");
	rra(a);
}