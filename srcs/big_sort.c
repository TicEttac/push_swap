#include "push_swap.h"

t_list	*find_max(t_list **a)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *a;
	max = (*a);
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	find_biggest_ascendant_sublist(t_list *max, t_list **a, t_list **start)
{
	int	size;
	int	next_size;
	t_list	*tmp;
	t_list	*save;

	size = 0;
	next_size = -1;
	tmp = *a;
	*start = *a;
	save = *a;
	while (tmp && tmp != max)
	{
		if (next_size == -1 && tmp->next && tmp->next->content < tmp->content)
			next_size = find_biggest_ascendant_sublist(max, &tmp->next, start);
		tmp = tmp->next;
		if (save->content < tmp->content)
		{
			save = tmp;
			size++;
		}
	}
	if (next_size >= size)
		return (next_size);
	*start = *a;
	return (size);
}

void	find_second_sublist_end(t_list *max, t_list **a, t_list **end)
{
	t_list	*tmp;

	find_biggest_ascendant_sublist(max, a, end);
	tmp = *end;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->content > (*end)->content)
			*end = tmp;
	}
}

void	first_push(t_list **a, t_list **b, t_list *start1, t_list *end2)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp && tmp != start1)
	{
		pb(a, b);
		ft_putstr("pb\n");
		tmp = *a;
	}
	while (end2->next)
	{
		rra(a);
		pb(a, b);
		ft_putstr("rra\npb\n");
	}
}

t_list	*push_sublist_b(t_list **a, t_list **b, t_list *max, t_list *sub2_end)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next != NULL && tmp->content != max->content)
	{
		if (tmp->next->content < tmp->content)
		{
			rotate_a(a);
			push_b(a, b);
		}
		tmp = tmp->next;
	}
}

void	big_sort(t_list **a)
{
	t_list	*max;
	t_list	*tmp;
	t_list	*b;
	t_list	*sub2_end;
	t_list	*sub_start;

	b = NULL;
	tmp = *a;
	max = find_max(a);
	find_biggest_ascendant_sublist(max, a, &sub_start);
	while (tmp->next)
		tmp = tmp->next;
	find_second_sublist_end(tmp, &max, &sub2_end);
	printf("start[%d]\n", sub_start->content);
	printf("end2[%d]\n", sub2_end->content);
	first_push(a, &b, sub_start, sub2_end);
	b = push_sublists_b(a, &b, max, sub2_end);
	print_list(a, 'a');
	print_list(b, 'b');
}
