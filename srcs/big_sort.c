#include "push_swap.h"

t_lis	*find_lis(t_list **a)
{
	t_list	*dup;
	t_lis	*lis;

	dup = list_dup(a);
	if (!dup)
		return (NULL);
	rotate_to_min(&dup);
	lis = build_lis(&dup);
	free_list(dup);
	return (lis);
}

void	move_b(t_list **a, t_list **b, t_list *element)
{
	t_list	*tmp;
	int		i;
	int		size;

	tmp = *a;
	size = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	tmp = *a;
	i = 0;
	while (tmp && tmp != element)
	{
		tmp = tmp->next;
		i++;
	}
	if (size - i < i)
		while (i <= size)
		{
			revrotate_a(a);
			i++;
		}
	else
		while (i)
		{
			rotate_a(a);
			i--;
		}
	push_b(a, b);
}

t_list	*big_build_b(t_list **a, t_lis *lis)
{
	t_list	*b;
    int     med;

	b = NULL;
    med = find_median(a);
    push_med(a, &b, lis, med, LESS);
    push_med(a, &b, lis, med, MORE);
	return (b);
}

void    merge(t_list **a, t_list **b)
{
	while (*b)
		move_a(a, b, best_push(a, b));
}

void	big_sort(t_list **a)
{
	t_list	*b;
	t_lis	*lis;

	lis = find_lis(a);
	b = big_build_b(a, lis);
	free(lis->content);
	free(lis);
    merge(a, &b);
    rotate_to_min_ex(a);
	free_list(b);
}