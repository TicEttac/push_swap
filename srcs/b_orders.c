#include "push_swap.h"

void	sb(t_list **b)
{
	t_list	*tmp;

	if ((*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = (*b)->next->next;
		tmp->next = *b;
		(*b) = tmp;
	}
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;
	
	tmp = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = tmp;
}

void	rb(t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *b;
	(*b) = (*b)->next;
	tmp->next->next = NULL;
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *b;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *b;
	tmp2 = tmp->next;
	tmp->next = NULL;
	*b = tmp2;
}
