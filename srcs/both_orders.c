/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_orders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:34:02 by nisauvig          #+#    #+#             */
/*   Updated: 2021/10/21 23:34:03 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}

void    rotate_both(t_list **a, t_list **b)
{
    if (!(*b)->next)
        rotate_a(a);
    else
    {
        printf("rr\n");
        rr(a, b);
    }
}

void    revrotate_both(t_list **a, t_list **b)
{
    if (!(*b)->next)
        revrotate_a(a);
    else
    {
        printf("rrr\n");
        rrr(a, b);
    }
}