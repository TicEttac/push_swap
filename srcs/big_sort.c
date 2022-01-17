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
		push_b(a, b);
		tmp = *a;
	}
	while (end2->next)
	{
		revrotate_a(a);
		push_b(a, b);
	}
}

t_list	*push_sublist_b(t_list **a, t_list **b, t_list *max, t_list *sub2_end)
{
	t_list	*tmp;
	int		ra;
	int		size;

	(void)sub2_end; //TODO : finish from front (keep max in a and last element) && take from the back
	tmp = *a;
	while ((*a)->next != NULL && tmp->content != max->content)
	{
		tmp = *a;
		ra = 0;
		size = list_size(*a);
		if (tmp->next->content < tmp->content && tmp->content != max->content)
		{
			rotate_a(a);
			push_b(a, b);
		}
		else if (tmp->content != max->content)
		{
			while (tmp->next->content > tmp->content && tmp->content != max->content)
			{
				ra++;
				tmp = tmp->next;
			}
			if (size - ra > ra)
				while (ra--)
					rotate_a(a);
			else
				while (size - ra != size)
					revrotate_a(a);
			push_b(a, b);
		}
	}
	return (*b);
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
	first_push(a, &b, sub_start, sub2_end);
	b = push_sublist_b(a, &b, max, sub2_end);
	print_list(*a, 'a');
	print_list(b, 'b');
}
